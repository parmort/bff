#include "bff.hpp"

namespace bff {

using std::filesystem::current_path;

BFF::BFF(int parent_size)
    : m_path(std::filesystem::current_path()), running(true),
      m_ev(make_unique<EventHandler>()),
      m_parent(make_unique<ParentBrowser>(m_path, parent_size, 1, 0)),
      m_browser(
          make_unique<Browser>(m_path, (parent_size) + 1, 1, (parent_size)-1)),
      m_command_line(make_unique<CommandLine>(LINES - 1, 0)),
      m_title_bar(make_unique<TitleBar>(m_path, 0, 0)),
      m_key_handler(make_unique<KeyHandler>(m_ev)),
      m_cmd_handler(make_unique<CommandHandler>(m_ev)) {
  m_ev->subscribe(m_parent.get());
  m_ev->subscribe(m_browser.get());
  m_ev->subscribe(m_title_bar.get());
  m_ev->subscribe(this);
}

int BFF::run() {
  m_ev->notify(Event::Populate);

  while (running) {
    m_ev->notify(Event::Redraw);
    m_key_handler->handle_key(getch());
  }

  return 0;
}

void BFF::accept(Event e) {
  switch (e) {
  case Event::Ascend:
    ascend();
    break;
  case Event::Descend:
    descend();
    break;
  case Event::CommandMode:
    command_mode();
    break;
  case Event::Quit:
    running = false;
    break;
  default:
    break;
  }
}

void BFF::ascend() {
  path sel = m_path;
  m_path = path(m_path.parent_path());

  m_ev->notify(Event::Populate);
  m_browser->select(sel);
}

void BFF::descend() {
  directory_entry child = m_browser->get_selected();

  if (!child.is_directory())
    return;

  m_path = path(child);
  m_ev->notify(Event::Populate);
}

void BFF::command_mode() {
  string cmd = m_command_line->get_command();
  m_cmd_handler->parse(cmd);
}

} // namespace bff
