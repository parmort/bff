#include "fs.hpp"

namespace bff {

FS::FS() : FS(fs::current_path()) {}

FS::FS(fs::path cwd) : m_cwd(cwd) {}

directory_contents *FS::dir_contents(fs::path path) {
  directory_contents *dir = new directory_contents();

  for (auto const &dir_entry : fs::directory_iterator{path})
    dir->push_back(dir_entry);

  return dir;
}

} // namespace bff
