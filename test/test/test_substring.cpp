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

TEST(SubstringTest, SinSubcadenaComun)
{
    string a = "abc";
    string b = "xyz";
    auto [start, end, sub] = substringComunMasLargo(a, b);
    EXPECT_EQ(sub, "");
}

TEST(SubstringTest, SubcadenaCompleta)
{
    string a = "abcdef";
    string b = "abcdef";
    auto [start, end, sub] = substringComunMasLargo(a, b);
    EXPECT_EQ(sub, "abcdef");
}

TEST(SubstringTest, SinCoincidencia)
{
    string a = "abc";
    string b = "xyz";
    auto [start, end, sub] = substringComunMasLargo(a, b);
    EXPECT_EQ(sub, "");
    EXPECT_EQ(end - start, -1); // nada encontrado
}
