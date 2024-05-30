#include "command.hpp"

namespace bff {

CommandHandler::CommandHandler(unique_ptr<EventHandler> &ev) : m_ev(ev) {}

void CommandHandler::parse(string cmd) {
  if (cmd == ":q") {
    m_ev->notify(Event::Quit);
    return;
  }
}

}
