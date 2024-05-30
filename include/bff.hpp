#pragma once

#include "common.hpp"
#include "components/browser.hpp"
#include "components/parent_browser.hpp"
#include "components/command_line.hpp"
#include "components/title_bar.hpp"
#include "components/window.hpp"
#include "key_handler.hpp"
#include "event_handler.hpp"
#include "command.hpp"

namespace bff {

class BFF : public IEventListener {
public:
  BFF(int parent_size);
  int run();

  void accept(Event e) override;

private:
  void ascend();
  void descend();
  void command_mode();

  path m_path;
  bool running;

  unique_ptr<EventHandler> m_ev;

  unique_ptr<ParentBrowser> m_parent;
  unique_ptr<Browser> m_browser;
  unique_ptr<TitleBar> m_title_bar;
  unique_ptr<CommandLine> m_command_line;

  unique_ptr<KeyHandler> m_key_handler;
  unique_ptr<CommandHandler> m_cmd_handler;
};

} // namespace bff
