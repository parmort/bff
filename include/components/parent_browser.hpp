#pragma once

#include "common.hpp"
#include "components/browser.hpp"

namespace bff {

class ParentBrowser : public Browser {
public:
  ParentBrowser(int width, int y, int x, BorderChars border);

  void populate(fs::path path);
};

}
