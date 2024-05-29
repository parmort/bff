#pragma once

#include "common.hpp"
#include "window.hpp"
#include "event_handler.hpp"

namespace bff {

class TitleBar : Window, public IEventListener {
public:
  TitleBar(const path &p, int y, int x);

  void accept(Event e) override;

private:
  string cwd();

  const path &m_path;
};

} // namespace bff
