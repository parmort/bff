#pragma once

#include "common.hpp"
#include "components/browser.hpp"

namespace bff {

class ParentBrowser : public Browser {
public:
  ParentBrowser(const path &p, int width, int y, int x);

  void populate();
};

} // namespace bff
