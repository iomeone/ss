
#include <purescript.h>

FOREIGN_BEGIN( Data_Enum )

// foreign import toCharCode :: Char -> Int
exports["toCharCode"] = [](const boxed& c_) -> boxed {

   
	const int   i = unbox<int>(c_);
	if (i > 0x0010ffff || i < 0)
	{
	
		const string  s = unbox<string>(c_);
	}
	
 
  return i;
};

FOREIGN_END
