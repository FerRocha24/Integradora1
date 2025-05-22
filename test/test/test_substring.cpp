#include <gtest/gtest.h>
#include "analizador.h"
#include "utils.h"

TEST(SubstringTest, DetectaComun)
{
    string a = "12345abcdef";
    string b = "xxabcdezz";
    auto [start, end, sub] = substringComunMasLargo(a, b);
    EXPECT_EQ(sub, "abcde");
}
