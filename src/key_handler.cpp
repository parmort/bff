#include "key_handler.hpp"

namespace bff {

KeyHandler::KeyHandler(unique_ptr<CommandLine> &cmd_line,
                       unique_ptr<Browser> &browser,
                       unique_ptr<ParentBrowser> &parent, path &p)
    : m_cmd_line(cmd_line), m_browser(browser), m_parent(parent), m_path(p) {}

Signal KeyHandler::handle_key(char c) {
  switch (c) {
  case keys::EnterCommandLine: {
    string cmd = m_cmd_line->get_command();
    return parse_command(cmd);
  }
  case keys::MoveSelectionDown:
    return m_browser->move_down();
  case keys::MoveSelectionUp:
    return m_browser->move_up();
  case keys::Descend:
    return descend();
  case keys::Ascend:
    return ascend();
  default:
    return Signal::Continue;
  }
}

Signal KeyHandler::parse_command(string cmd) {
  if (cmd == ":q") {
    return Signal::Quit;
  }

  return Signal::Continue;
}

Signal KeyHandler::ascend() {
  path sel = m_path;
  m_path = path(m_path.parent_path());

  m_parent->populate();
  m_browser->populate();

  m_browser->select(sel);

  return Signal::Continue;
}

Signal KeyHandler::descend() {
  directory_entry child = m_browser->get_selected();

  if (!child.is_directory())
    return Signal::Continue;

  m_path = path(child);

  m_parent->populate();
  m_browser->populate();

  return Signal::Continue;
}

} // namespace bff
