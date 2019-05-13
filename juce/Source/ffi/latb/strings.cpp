#include <algorithm>
#include <locale>
#include <codecvt>
#include <regex>
#include <sstream>
#include <iostream>
#include <cassert>

#include <purescript.h>

static std::wstring_convert<std::codecvt_utf8<__int32 >, __int32 > utf32conv;

FOREIGN_BEGIN( Data_String_Common )

// foreign import replace :: Pattern -> Replacement -> String -> String
//
exports["replace"] = [](const boxed& s1) -> boxed {
  return [=](const boxed& s2) -> boxed {
    return [=](const boxed& s3) -> boxed {
      string ss(unbox<string>(s3));
      string sp(unbox<string>(s1));
      const auto found = ss.find(unbox<string>(sp));
      return found == string::npos ? ss : ss.replace(found, sp.size(), unbox<string>(s2));
    };
  };
};

FOREIGN_END

FOREIGN_BEGIN( Data_String_CodeUnits )


// foreign import length :: String -> Int

exports["length"] = [](const boxed& s_) -> boxed {
  const string& s = unbox<string>(s_);
  const int sz = s.size();
  assert(sz <= std::numeric_limits<int>::max());
  return sz;
};

// foreign import singleton :: Char -> String
//
exports["singleton"] = [](const boxed& c_) -> boxed {
  return unbox<string>(c_);
};

// foreign import toCharArray :: String -> Array Char
//
exports["toCharArray"] = [](const boxed& s_) -> boxed {
  array_t cs;
  const string& s = unbox<string>(s_);
  for (char c : s) {
    cs.emplace_back(boxed(string(1,c)));
  };
  return cs;
};

// foreign import fromCharArray :: Array Char -> String
//
exports["fromCharArray"] = [](const boxed& xs_) -> boxed {
    array_t xs = unbox<array_t>(xs_);
    std::stringstream result;
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
      result << unbox<string>(*it);
    }
    return result.str();
};

// foreign import drop :: Int -> String -> String
//
exports["drop"] = [](const boxed& n_) -> boxed {
  return [=](const boxed& s_) -> boxed {
    auto n = unbox<int>(n_);
    const string& s = unbox<string>(s_);
    return n <= 0 ? s : n >= s.size() ? "" : s.substr(n);
  };
};

// -- Returns the first `n` characters of the string.
// foreign import take :: Int -> String -> String
exports["take"] = [](const boxed& n_) -> boxed {
  return [=](const boxed& s_) -> boxed {
    const string& s = unbox<string>(s_);
    auto n = std::max(unbox<int>(n_), 0);
    auto l = s.size();
    return n >= l ? s : (n < 1 ? string("") : s.substr(0, n));
  };
};

exports["countPrefix"] = [](const boxed& f_) -> boxed {
  return [=](const boxed& s_) -> boxed {
    const string& s = unbox<string>(s_);
    int i = 0;
    while ( i<s.length() && unbox<bool>(f_(boxed(s.substr(i, 1)))) ) i++;
    return i;
  };
};

// foreign import _indexOf :: (forall a. a -> Maybe a) -> (forall a. Maybe a) -> Pattern -> String -> Maybe Int
//
exports["_indexOf"] = [](const boxed& just_) -> boxed {
  return [=](const boxed& nothing_) -> boxed {
    return [=](const boxed& p_) -> boxed {
      return [=](const boxed& s_) -> boxed {
        const string& p = unbox<string>(p_);
        const string& s = unbox<string>(s_);
        //std::size_t found = s.find(p);
#ifdef _WIN64
		 int              found = s.find(p);
#else
		 int              found = s.find(p);
#endif
        return found==std::string::npos ? nothing_ : just_( found);
      };
    };
  };
};





/*   const char * p = purs_any_get_string(p0); */
/*   const char * s = purs_any_get_string(s0); */
/*   const char * found = strstr(s, p); */
/*   if (!found) return nothing; */
/*   return purs_any_app(just, purs_any_int_new(found-s)); */

FOREIGN_END












FOREIGN_BEGIN(Data_String_CodePoints)
//foreign import _unsafeCodePointAt0
//:: (String->CodePoint)
//->String
//->CodePoint

exports["_unsafeCodePointAt0"] = [](const boxed& fallBack) -> boxed {

	return [=](const boxed & str) -> boxed {
		const string& s = unbox<string>(str);
		if (s.length() < 1)
		{
			return fallBack(str);
		}
		else
		{
			return s[0];
		}
	};

};




exports["_toCodePointArray"] = [](const boxed& fallBack) -> boxed{

	return [=](const boxed & unsafeCodePointAt0) -> boxed {

		return [=](const boxed & str) -> boxed {

			const string& s = unbox<string>(str);
			if (s.length() < 1)
			{
				return fallBack();
			}
			else
			{
				array_t result;
			
				for (char c : s) {
					result.emplace(boxed(int(c)));
				}
				return result;
			}
		};
	};


};






FOREIGN_END

