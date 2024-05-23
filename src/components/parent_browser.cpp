#include <algorithm>

#include "components/parent_browser.hpp"

namespace bff {

ParentBrowser::ParentBrowser(int width, int y, int x, BorderChars border)
    : Browser(width, y, x, border) {}

void ParentBrowser::populate(fs::path path) {
  m_directory = FS::dir_contents(path.parent_path());
  std::sort(m_directory->begin(), m_directory->end(), compare_entries);
  select(path);
}

} // namespace bff
