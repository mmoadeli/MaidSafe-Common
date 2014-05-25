/*  Copyright 2012 MaidSafe.net limited

    This MaidSafe Software is licensed to you under (1) the MaidSafe.net Commercial License,
    version 1.0 or later, or (2) The General Public License (GPL), version 3, depending on which
    licence you accepted on initial access to the Software (the "Licences").

    By contributing code to the MaidSafe Software, or to this project generally, you agree to be
    bound by the terms of the MaidSafe Contributor Agreement, version 1.0, found in the root
    directory of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also
    available at: http://www.maidsafe.net/licenses

    Unless required by applicable law or agreed to in writing, the MaidSafe Software distributed
    under the GPL Licence is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
    OF ANY KIND, either express or implied.

    See the Licences for the specific language governing permissions and limitations relating to
    use of the MaidSafe Software.                                                                 */

#ifndef MAIDSAFE_COMMON_MENU_ITEM_H_
#define MAIDSAFE_COMMON_MENU_ITEM_H_

#include <cstdint>
#include <utility>
#include <string>
#include <tuple>
#include <functional>

#include "maidsafe/common/menu_level.h"

namespace maidsafe {

typedef std::function<void()> Func;

struct MenuItem{
  MenuItem(std::string name, MenuLevel level, Func func)
      : name(name), level(level), target_level(level), run(func) {}

  MenuItem(std::string name, MenuLevel level, MenuLevel target_level)
      : name(name), level(level), target_level(target_level) {}

  ~MenuItem() = default;

  MenuItem(const MenuItem& other) = default;
  MenuItem(MenuItem&& other)
      : name(std::move(other.name)),
        level(std::move(other.level)),
        target_level(std::move(other.level)),
        run(std::move(other.run)) {}

  void swap(MenuItem& lhs, MenuItem& rhs) noexcept {
    using std::swap;
    swap(lhs.name, rhs.name);
    swap(lhs.level, rhs.level);
    swap(lhs.target_level, rhs.target_level);
    swap(lhs.run, rhs.run);
  }

  MenuItem& operator=(MenuItem other) {
    swap(*this, other);
    return *this;
  }

  friend
  bool operator==(const MenuItem& lhs, const MenuItem& rhs) {
    return std::tie(lhs.name, lhs.level, lhs.target_level)
        == std::tie(rhs.name, rhs.level, rhs.target_level);
  }

  friend
  bool operator!=(const MenuItem& lhs, const MenuItem& rhs) {
    return !operator==(lhs, rhs);
  }

 std::string name;
  MenuLevel level;
  MenuLevel target_level;
  Func run;
};





}  // namespace maidsafe

#endif  // MAIDSAFE_COMMON_MENU_ITEM_H_
