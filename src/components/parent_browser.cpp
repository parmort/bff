#include <algorithm>

#include "components/parent_browser.hpp"
#include "fs.hpp"

namespace bff {

ParentBrowser::ParentBrowser(const path &p, int width, int y, int x,
                             BorderChars border)
    : Browser(p, width, y, x, border) {}

void ParentBrowser::populate() {
  m_directory = fs::get_dir_contents(m_path.parent_path());
  std::sort(m_directory.begin(), m_directory.end(), compare_entries);
  select(m_path.parent_path());
}

} // namespace bff