#include "fs.hpp"

namespace bff {

FS::FS(fs::path cwd) : m_cwd(cwd) {}
FS::FS() : FS(fs::current_path()) {}

vector<fs::directory_entry>* FS::dir_contents(fs::path path) {
  vector<fs::directory_entry> *contents = new vector<fs::directory_entry>();

  for (auto const &dir_entry : fs::directory_iterator{path}) {
    contents->push_back(dir_entry);
  }

  return contents;
}

} // namespace bff
