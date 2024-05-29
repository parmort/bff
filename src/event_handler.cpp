#include "event_handler.hpp"

namespace bff {

EventHandler::EventHandler() : m_listeners() {}

void EventHandler::subscribe(IEventListener *listener) {
  m_listeners.push_back(listener);
}

void EventHandler::notify(Event e) {
  for (IEventListener *listener : m_listeners) {
    listener->accept(e);
  }
}

} // namespace bff
