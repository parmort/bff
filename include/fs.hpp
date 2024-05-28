#pragma once

#include <filesystem>
#include <vector>

#include "common.hpp"

namespace bff::fs {

typedef vector<directory_entry> dir_contents;

dir_contents get_dir_contents(path);

} // namespace bff::fs
