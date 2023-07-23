// Copyright (C) 2023 Joel Rosdahl and other contributors
//
// See doc/AUTHORS.adoc for a complete list of contributors.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#include "common.hpp"

#include <core/exceptions.hpp>
#include <fmtmacros.hpp>
#include <util/filesystem.hpp>

namespace fs = util::filesystem;

namespace core {

void
ensure_dir_exists(std::string_view dir)
{
  if (auto result = fs::create_directories(dir); !result) {
    throw core::Fatal(
      FMT("Failed to create directory {}: {}", dir, result.error().message()));
  }
}

} // namespace core