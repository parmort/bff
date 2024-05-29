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
  void build();

  const path &m_path;
};

} // namespace bff
