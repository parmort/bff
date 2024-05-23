#include "bff.hpp"

namespace bff {

BFF::BFF()
    : m_sidebar(new ParentBrowser(COLS / 2, 1, 0, BorderChars())),
      m_browser(new Browser((COLS / 2) + 1, 1, (COLS / 2) - 1,
                            {.tl = ACS_TTEE, .bl = ACS_BTEE})),
      m_command_line(new CommandLine(LINES - 1, 0)),
      m_title_bar(new TitleBar(0, 0)), fs(std::make_unique<FS>(FS())) {}

int BFF::run() {
  Signal sig = Signal::Continue;

  m_sidebar->populate(fs->cwd());
  m_browser->populate(fs->cwd());

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
    fs::path p;

    if (not m_browser->descend(&p))
      break;

    fs.reset(new FS(p));

    m_sidebar->populate(fs->cwd());
    m_browser->populate(fs->cwd());

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
