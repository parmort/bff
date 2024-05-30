#include "key_handler.hpp"

namespace bff {

KeyHandler::KeyHandler(unique_ptr<EventHandler> &ev)
    : m_ev(ev) {}

void KeyHandler::handle_key(char c) {
  switch (c) {
  case keys::EnterCommandLine:
    m_ev->notify(Event::CommandMode);
    break;
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
}

} // namespace bff
