#include "fs.hpp"

namespace bff {

FS::FS(fs::path cwd) : m_cwd(cwd) {}
FS::FS() : FS(fs::current_path()) {}

} // namespace bff
