#pragma once

#include "common.hpp"
#include "components/command_line.hpp"
#include "components/browser.hpp"
#include "components/parent_browser.hpp"

namespace bff {

namespace keys {
enum Mappings : char {
  EnterCommandLine = ':',
  MoveSelectionDown = 'j',
  MoveSelectionUp = 'k',
  Descend = 'l',
  Ascend = 'h'
};
}

class KeyHandler {
public:
  KeyHandler(unique_ptr<EventHandler> &ev);

  void handle_key(char c);

private:
  unique_ptr<EventHandler> &m_ev;
};

} // namespace bff
