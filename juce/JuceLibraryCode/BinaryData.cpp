/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== LICENSE ==================
static const unsigned char temp_binary_data_0[] =
"MIT License\n"
"\n"
"Copyright (c) 2018 Andy Arvanitis\n"
"\n"
"Permission is hereby granted, free of charge, to any person obtaining a copy\n"
"of this software and associated documentation files (the \"Software\"), to deal\n"
"in the Software without restriction, including without limitation the rights\n"
"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
"copies of the Software, and to permit persons to whom the Software is\n"
"furnished to do so, subject to the following conditions:\n"
"\n"
"The above copyright notice and this permission notice shall be included in all\n"
"copies or substantial portions of the Software.\n"
"\n"
"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
"SOFTWARE.\n";

const char* LICENSE = (const char*) temp_binary_data_0;

//================== purescript-native-ffi-master-ex.7z ==================
static const unsigned char temp_binary_data_1[] =
{ 55,122,188,175,39,28,0,4,36,220,105,112,102,0,0,0,0,0,0,0,33,0,0,0,0,0,0,0,156,77,160,64,0,0,129,122,148,157,242,189,227,202,137,184,214,71,252,120,245,67,36,107,217,103,194,74,18,74,194,193,190,181,73,45,130,33,128,216,28,239,92,12,23,240,211,160,203,
80,229,102,62,197,156,129,93,251,17,89,94,125,37,248,169,78,253,113,158,158,170,236,209,33,31,75,126,194,230,156,124,182,135,106,49,61,22,47,127,232,17,180,115,134,227,85,65,110,253,253,122,143,94,159,112,0,23,6,0,1,9,102,0,7,11,1,0,1,35,3,1,1,5,93,0,
16,0,0,12,128,238,10,1,167,83,217,152,0,0,0,0 };

const char* purescriptnativeffimasterex_7z = (const char*) temp_binary_data_1;

//================== README.md ==================
static const unsigned char temp_binary_data_2[] =
"### C++ foreign export implementations for the standard library\n"
"\n"
"Note that many values are currently missing. Only a minimum set has been implemented \xe2\x80\x93 just beyond enough for the standard compiler tests to pass. Please feel free to contribute any that you have implemented yourself (via a pull request).\n";

const char* README_md = (const char*) temp_binary_data_2;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x34bc1021:  numBytes = 1071; return LICENSE;
        case 0xb283c3de:  numBytes = 167; return purescriptnativeffimasterex_7z;
        case 0x64791dc8:  numBytes = 306; return README_md;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "LICENSE",
    "purescriptnativeffimasterex_7z",
    "README_md"
};

const char* originalFilenames[] =
{
    "LICENSE",
    "purescript-native-ffi-master-ex.7z",
    "README.md"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
