#include "bff.hpp"

namespace bff {

using std::filesystem::current_path;

BFF::BFF()
    : m_path(std::filesystem::current_path()),
      m_sidebar(new ParentBrowser(m_path, COLS / 2, 1, 0, BorderChars())),
      m_browser(new Browser(m_path, (COLS / 2) + 1, 1, (COLS / 2) - 1,
                            {.tl = ACS_TTEE, .bl = ACS_BTEE})),
      m_command_line(new CommandLine(LINES - 1, 0)),
      m_title_bar(new TitleBar(0, 0)) {}

BFF::~BFF() {
  delete m_sidebar;
  delete m_browser;
  delete m_command_line;
  delete m_title_bar;
}

int BFF::run() {
  Signal sig = Signal::Continue;

  m_sidebar->populate();
  m_browser->populate();

  while (sig == Signal::Continue) {
    m_sidebar->redraw();
    m_browser->redraw();

    sig = handle_key(getch());
  }

  return 0;
}

Signal BFF::handle_key(char c) {
  Signal sig = Signal::Continue;

  switch (c) {
  case ':': {
    string cmd = m_command_line->get_command();
    sig = parse_command(cmd);
    break;
  }
  case 'j': {
    m_browser->move_down();
    break;
  }
  case 'k': {
    m_browser->move_up();
    break;
  }
  case 'l': {
    m_path = path(m_browser->get_selected());

    m_sidebar->populate();
    m_browser->populate();

    break;
  }
  case 'h': {
    path sel = m_path;
    m_path = path(m_path.parent_path());

    m_sidebar->populate();
    m_browser->populate();

    m_browser->select(sel);

    break;
  }
  }

  return sig;
}

Signal BFF::parse_command(string cmd) {
  if (cmd == ":q") {
    return Signal::Quit;
  }

  return Signal::Continue;
}

} // namespace bff
