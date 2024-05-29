#include "key_handler.hpp"

namespace bff {

KeyHandler::KeyHandler(unique_ptr<CommandLine> &cmd_line,
                       unique_ptr<EventHandler> &ev)
    : m_cmd_line(cmd_line), m_ev(ev) {}

Signal KeyHandler::handle_key(char c) {
  switch (c) {
  case keys::EnterCommandLine: {
    string cmd = m_cmd_line->get_command();
    return parse_command(cmd);
  }
  case keys::MoveSelectionDown:
    m_ev->notify(Event::SelectionDown);
    break;
  case keys::MoveSelectionUp:
    m_ev->notify(Event::SelectionUp);
    break;
  case keys::Descend:
    m_ev->notify(Event::Descend);
    break;
  case keys::Ascend:
    m_ev->notify(Event::Ascend);
    break;
  }

  return Signal::Continue;
}

Signal KeyHandler::parse_command(string cmd) {
  if (cmd == ":q") {
    return Signal::Quit;
  }

  return Signal::Continue;
}

} // namespace bff
