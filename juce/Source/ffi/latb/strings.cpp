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
      std::string ss = (unbox<juce::String>(s3)).toStdString();
      std::string sp = (unbox<juce::String>(s1)).toStdString();
	  std::string s2_ = (unbox<juce::String>(s2)).toStdString();
      const auto found = ss.find(sp);
      return found == std::string::npos ? ss : ss.replace(found, sp.size(), s2_);
    };
  };
};


//	split::Pattern->String->Array String

exports["split"] = [](const boxed& p_) -> boxed {
	return [=](const boxed& src_) -> boxed {
		const juce::String& p = unbox<juce::String>(p_);
		const juce::String& s = unbox<juce::String>(src_);

		size_t pos_start = 0, pos_end, delim_len = p.length();
		juce::String token;
		array_t res;
		if ( s.length() == 0)
		{
			return res;
		}

		if (p.length() == 0 )
		{
			res.push_back(boxed(s));
			return res;
		}

		if (p.length() > 0 && s.length() > 0)
		{
			while ((pos_end = s.indexOf(pos_start, p )) != -1) {
				token = s.substring(pos_start, pos_end);
				pos_start = pos_end + delim_len;
				res.push_back(boxed(token));
			}

			res.push_back(boxed(s.substring(pos_start)));
		}
		return res;

	};
};





FOREIGN_END

FOREIGN_BEGIN( Data_String_CodeUnits )


// foreign import length :: String -> Int

exports["length"] = [](const boxed& s_) -> boxed {
  const juce::String& s = unbox<juce::String>(s_);
  const int sz = s.length();
  assert(sz <= std::numeric_limits<int>::max());
  return sz;
};

// foreign import singleton :: Char -> String
//
exports["singleton"] = [](const boxed& c_) -> boxed {
  return unbox<juce::String>(c_);
};

// foreign import toCharArray :: String -> Array Char
//
exports["toCharArray"] = [](const boxed& s_) -> boxed {
  array_t cs;
  const juce::String& s = unbox<juce::String>(s_);

  for (int i = 0; i < s.length(); i++)
  {
	  juce::String tmp = "";
	  tmp += s[i];
	  cs.emplace_back(boxed(tmp));
  }
  //for (char c : s) {
  //  cs.emplace_back(boxed(string(1,c)));
  //};
  return cs;
};

// foreign import fromCharArray :: Array Char -> String
//
exports["fromCharArray"] = [](const boxed& xs_) -> boxed {
    array_t xs = unbox<array_t>(xs_);
    std::stringstream result;
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
      result << unbox<juce::String>(*it);
    }
    return result.str();
};

// foreign import drop :: Int -> String -> String
//
exports["drop"] = [](const boxed& n_) -> boxed {
  return [=](const boxed& s_) -> boxed {
    auto n = unbox<int>(n_);
    const juce::String& s = unbox<juce::String>(s_);
    return n <= 0 ? s : n >= s.length() ? "" : s.substring(n);
  };
};

// -- Returns the first `n` characters of the string.
// foreign import take :: Int -> String -> String
exports["take"] = [](const boxed& n_) -> boxed {
  return [=](const boxed& s_) -> boxed {
    const juce::String& s = unbox<juce::String>(s_);
    auto n = std::max(unbox<int>(n_), 0);
    auto l = s.length();
    return n >= l ? s : (n < 1 ? juce::String("") : s.substring(0, n));
  };
};

exports["countPrefix"] = [](const boxed& f_) -> boxed {
  return [=](const boxed& s_) -> boxed {
    const juce::String& s = unbox<juce::String>(s_);
    int i = 0;
    while ( i<s.length() && unbox<bool>(f_(boxed(s.substring(i, 1)))) ) i++;
    return i;
  };
};

// foreign import _indexOf :: (forall a. a -> Maybe a) -> (forall a. Maybe a) -> Pattern -> String -> Maybe Int
//
exports["_indexOf"] = [](const boxed& just_) -> boxed {
  return [=](const boxed& nothing_) -> boxed {
    return [=](const boxed& p_) -> boxed {
      return [=](const boxed& s_) -> boxed {
        const juce::String& p = unbox<juce::String>(p_);
        const juce::String& s = unbox<juce::String>(s_);
        //std::size_t found = s.find(p);
#ifdef _WIN64
		 int              found = s.indexOf(p);
#else
		 int              found = s.indexOf(p);
#endif
        return found== -1 ? nothing_ : just_( found);
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
		const juce::String& s = unbox<juce::String>(str);
		if (s.length() < 1)
		{
			return fallBack(str);
			//return fallBack(); this code also compile, which one I should use??
		}
		else
		{
			return int(s[0]); // the code is wrong , bcz chinese character takes 2 or more byte. 
		}
	};

};




exports["_toCodePointArray"] = [](const boxed& fallBack) -> boxed{

	return [=](const boxed & unsafeCodePointAt0) -> boxed {

		return [=](const boxed & str) -> boxed {

			const juce::String& s = unbox<juce::String>(str);
			if (s.length() < 1)
			{
				//printf("fall back\n");
				return fallBack(str);
			}
			else
			{
				array_t result;
				for (int i = 0; i < s.length(); i++)
				{
					result.push_back(boxed(int(s[i])));
				}
			

				return result;
			}
		};
	};

};


// -- Returns the first `n` characters of the string.
// foreign import take :: Int -> String -> String
exports["_take"] = [](const boxed& fallBack) -> boxed {
	return [=](const boxed& n_) -> boxed {
		return [=](const boxed& s_) -> boxed {
			const juce::String& s = unbox<juce::String>(s_);
			auto n = std::max(unbox<int>(n_), 0);
			auto l = s.length();
			return n >= l ? s : (n < 1 ? juce::String("") : s.substring(0, n)); // the code is wrong , bcz chinese character takes 2 or more byte. 
		};
	};

};

FOREIGN_END








FOREIGN_BEGIN(Data_String_Unsafe)


//-- | Returns the character at the given index.
//-- |
//-- | **Unsafe:** throws runtime exception if the index is out of bounds.
//foreign import charAt::Int->String->Char


exports["charAt"] = [](const boxed& index_) -> boxed {
	return [=](const boxed& str_) -> boxed {
		const juce::String& str = unbox<juce::String>(str_);
		const int &  index = unbox<int>(index_);

		assert(str.length() >index && index >= 0);
		return str.substring(index, index+1);
	};
};


FOREIGN_END