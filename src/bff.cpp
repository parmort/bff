#include "bff.hpp"

namespace bff {

using std::filesystem::current_path;

BFF::BFF()
    : m_path(std::filesystem::current_path()),
      m_sidebar(new ParentBrowser(m_path, COLS / 2, 1, 0)),
      m_browser(new Browser(m_path, (COLS / 2) + 1, 1, (COLS / 2) - 1)),
      m_command_line(new CommandLine(LINES - 1, 0)),
      m_title_bar(new TitleBar(0, 0)),
      m_key_handler(
          new KeyHandler(m_command_line, m_browser, m_sidebar, &m_path)) {}

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

    sig = m_key_handler->handle_key(getch());
  }

  return 0;
}

} // namespace bff
