#pragma once

#include "common.hpp"
#include "event_handler.hpp"

namespace bff {

class CommandHandler {
public:
  CommandHandler(unique_ptr<EventHandler> &ev);

  void parse(string cmd);

private:
  unique_ptr<EventHandler> &m_ev;
};

}
