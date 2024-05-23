#include "components/browser.hpp"

namespace bff {

Browser::Browser(int width, int y, int x, BorderChars border)
  : Window(LINES - 2, width, y, x, border) {}

}
