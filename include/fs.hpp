#pragma once

#include <filesystem>

#include "common.hpp"

namespace bff {

namespace fs = std::filesystem;

class FS {
public:
  FS(fs::path cwd);
  FS();

  inline fs::path cwd() { return m_cwd; }
  inline fs::path parent() { return m_cwd.parent_path(); }

private:
  fs::path m_cwd;
};

} // namespace bff
