#include "bff.hpp"

namespace bff {

using std::filesystem::current_path;

BFF::BFF(int parent_size)
    : m_path(std::filesystem::current_path()),
      m_sidebar(make_unique<ParentBrowser>(m_path, parent_size, 1, 0)),
      m_browser(
          make_unique<Browser>(m_path, (parent_size) + 1, 1, (parent_size)-1)),
      m_command_line(make_unique<CommandLine>(LINES - 1, 0)),
      m_title_bar(make_unique<TitleBar>(0, 0)),
      m_key_handler(make_unique<KeyHandler>(m_command_line, m_browser,
                                            m_sidebar, m_path)) {}

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
