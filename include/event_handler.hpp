#pragma once

#include "common.hpp"

namespace bff {

enum class Event {
  Populate,
  Redraw,
  Ascend,
  Descend,
  SelectionUp,
  SelectionDown,
  CommandMode,
  Quit
};

class IEventListener {
public:
  virtual void accept(Event e) = 0;
};

class EventHandler {
public:
  EventHandler();

  void subscribe(IEventListener *listener);
  void notify(Event e);

private:
  vector<IEventListener *> m_listeners;
};

} // namespace bff
