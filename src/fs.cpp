#include "fs.hpp"

namespace bff::fs {

dir_contents get_dir_contents(path path) {
  dir_contents dir = dir_contents();

  for (auto const &dir_entry : std::filesystem::directory_iterator{path})
    dir.push_back(dir_entry);

  return dir;
}

} // namespace bff::fs
