///////////////////////////////////////////////////////////////////////////////
//
// Module      :  dictionary.h
// Copyright   :  (c) Andy Arvanitis 2018
// License     :  BSD
//
// Maintainer  :  Andy Arvanitis
// Stability   :  experimental
// Portability :
//
// A simple dictionary optimized for this runtime's particular use �C
// *not* intended for general use or as a replacement for containers
// such as std::map or std::unordered_map. It relies on the following
// assumptions:
//
//    1) Keys are C-type string literals. No copying or (memory management)
//       of the keys occurs
//    2) The number of elements in the container is generally small �C say,
//       under 20. There is no sorting and a linear search is used to
//       locate elements
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef purescript_dictionary_H
#define purescript_dictionary_H

#include <cstring>
#include <vector>
#include <utility>
#if !defined(NDEBUG)
#include <string>
#endif

namespace purescript {
    namespace _template_ {

    template <typename T>
    class dict_t : public std::vector<std::pair<const char *, T>> {

      static auto null() -> const T& {
        static const T value;
        return value;
      }

      public:
      using std::vector<std::pair<const char *, T>>::vector;

      auto operator[](const char key[]) const -> const T& {
        for (auto it = this->cbegin(), end=this->cend(); it != end; it++) {
          const auto& elem_key = it->first;
          if (elem_key == key || !std::strcmp(elem_key, key)) {
            return it->second;
          }
        }
#if !defined(NDEBUG) && !defined(PURESCRIPT_DISABLE_EXCEPTIONS)
        throw std::runtime_error("dictionary key \"" + std::string(key) + "\" not found");
#endif
        return null();
      }

      auto at(const char key[]) const -> const T& {
        return (*this)[key];
      }

      auto operator[](const char key[]) -> T& {
        const auto end = this->end();
        for (auto it = this->begin(); it != end; it++) {
          const auto& elem_key = it->first;
          if (elem_key == key || !std::strcmp(elem_key, key)) {
            return it->second;
          }
        }
        return this->emplace(end, key, T())->second;
      }

      auto contains(const char key[]) const -> bool {
        for (auto it = this->cbegin(), end=this->cend(); it != end; it++) {
          const auto& elem_key = it->first;
          if (elem_key == key || !std::strcmp(elem_key, key)) {
            return true;
          }
        }
        return false;
      }

    };

    } // namespace _template_
} // namespace purescript

#endif // purescript_dictionary_H
