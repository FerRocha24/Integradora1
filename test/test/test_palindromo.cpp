#include <string>
#include "analizador.h"
#include "gtest/gtest.h"

using std::string;

TEST(PalindromoTest, DetectaCorrectamente)
{
    string entrada = "abcddcba123";
    auto [inicio, fin, pal] = encontrarPalindromoMasLargo(entrada);
    EXPECT_EQ(pal, "abcddcba");
}
