#pragma once

#include <filesystem>
#include <vector>

#include "common.hpp"

namespace bff {

namespace fs = std::filesystem;
using std::vector;

class FS {
public:
  FS(fs::path cwd);
  FS();

  inline fs::path cwd() { return m_cwd; }
  inline fs::path parent() { return m_cwd.parent_path(); }

  static vector<fs::directory_entry>* dir_contents(fs::path);

private:
  fs::path m_cwd;
};

} // namespace bff
