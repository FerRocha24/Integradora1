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

TEST(PalindromoTest, DetectaPalindromoCentral)
{
    string texto = "abcxyzyxdef";
    auto [start, end, sub] = encontrarPalindromoMasLargo(texto);
    EXPECT_EQ(sub, "xyzyx");
    EXPECT_EQ(start, 4);
    EXPECT_EQ(end, 8);
}

TEST(PalindromoTest, DetectaPalindromoCorto)
{
    string texto = "abac";
    auto [start, end, sub] = encontrarPalindromoMasLargo(texto);
    EXPECT_EQ(sub, "aba");
    EXPECT_EQ(start, 1);
    EXPECT_EQ(end, 3);
}

TEST(PalindromoTest, PalindromoUnCaracter)
{
    string texto = "xyz";
    auto [start, end, sub] = encontrarPalindromoMasLargo(texto);
    EXPECT_EQ(sub.length(), 1);
}
