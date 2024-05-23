#include <filesystem>

#include "bff.hpp"

namespace bff {

BFF::BFF()
    : m_sidebar(new Window(LINES - 2, 26, 1, 0, BorderChars())),
      m_browser(new Window(LINES - 2, COLS - 25, 1, 25,
                           {.tl = ACS_TTEE, .bl = ACS_BTEE})),
      m_command_line(new CommandLine(LINES - 1, 0)),
      m_title_bar(new TitleBar(0, 0)) {}

int BFF::run() {
  Signal sig = Signal::Continue;

  char c;
  while (sig == Signal::Continue) {
    c = getch();
    switch (c) {
    case ':':
      string cmd = m_command_line->get_command();
      sig = parse_command(cmd);
      break;
    }
  }

  return 0;
}

Signal BFF::parse_command(string cmd) {
  if (cmd == ":q") {
    return Signal::Quit;
  }

  return Signal::Continue;
}

} // namespace bff
