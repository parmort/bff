#pragma once

#include <filesystem>
#include <vector>

#include "common.hpp"

namespace bff {

namespace fs = std::filesystem;
using std::vector;

typedef vector<fs::directory_entry> directory_contents;

class FS {
public:
  FS(fs::path cwd);
  FS();

  inline fs::path cwd() { return m_cwd; }
  inline fs::path parent() { return m_cwd.parent_path(); }
  static directory_contents *dir_contents(fs::path);

private:
  fs::path m_cwd;
};

} // namespace bff
