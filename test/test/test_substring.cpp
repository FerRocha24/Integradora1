#include <string>
#include "analizador.h"
#include "gtest/gtest.h"

using std::string;

TEST(SubstringTest, DetectaComun)
{
    string a = "12345abcdef";
    string b = "xxabcdezz";
    auto [start, end, sub] = substringComunMasLargo(a, b);
    EXPECT_EQ(sub, "abcde");
}
