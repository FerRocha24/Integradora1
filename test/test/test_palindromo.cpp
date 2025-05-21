#include <gtest/gtest.h>
#include "../analizador.h"

TEST(PalindromoTest, DetectaCorrectamente)
{
    string entrada = "abcddcba123";
    auto [inicio, fin, pal] = encontrarPalindromoMasLargo(entrada);
    EXPECT_EQ(pal, "abcddcba");
}
