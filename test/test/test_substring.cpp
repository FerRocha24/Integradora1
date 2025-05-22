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
    EXPECT_EQ(start, 6);
    EXPECT_EQ(end, 11);
}

TEST(SubstringTest, SinSubstringComun)
{
    string a = "abc";
    string b = "def";
    auto [start, end, sub] = substringComunMasLargo(a, b);
    EXPECT_EQ(sub, "");
    EXPECT_EQ(end - start, 0);
}

TEST(SubstringTest, SubstringCompleto)
{
    string a = "palabra";
    string b = "palabra";
    auto [start, end, sub] = substringComunMasLargo(a, b);
    EXPECT_EQ(sub, "palabra");
    EXPECT_EQ(start, 1);
    EXPECT_EQ(end, 7);
}