#include <algorithm>

#include "components/parent_browser.hpp"

namespace bff {

ParentBrowser::ParentBrowser(int width, int y, int x, BorderChars border)
    : Browser(width, y, x, border) {}

void ParentBrowser::populate(fs::path path) {
  m_directory = FS::dir_contents(path.parent_path());
  std::sort(m_directory->begin(), m_directory->end(), compare_entries);

  for (auto it = m_directory->begin(); it != m_directory->end(); ++it) {
    if (it->path().string() == path.string()) {
      m_sel = it - m_directory->begin();
      break;
    }
  }
}

} // namespace bff
