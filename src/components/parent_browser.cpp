#include <algorithm>

#include "components/parent_browser.hpp"
#include "fs.hpp"

namespace bff {

ParentBrowser::ParentBrowser(const path &p, int width, int y, int x)
    : Browser(p, width, y, x, BorderChars()) {}

void ParentBrowser::accept(Event e) {
  switch (e) {
  case Event::Populate:
    populate();
    break;
  default:
    Browser::accept(e);
    break;
  }
}

void ParentBrowser::populate() {
  m_sel = 0;
  m_directory = fs::get_dir_contents(m_path.parent_path());
  std::sort(m_directory.begin(), m_directory.end(), compare_entries);
  select(m_path);
}

} // namespace bff
