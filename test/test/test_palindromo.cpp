#include <string>
#include "analizador.h"
#include "gtest/gtest.h"

TEST(PalindromoTest, DetectaCorrectamente)
{
    string entrada = "abcddcba123";
    auto [inicio, fin, pal] = encontrarPalindromoMasLargo(entrada);
    EXPECT_EQ(pal, "abcddcba");
    EXPECT_EQ(inicio, 1);
    EXPECT_EQ(fin, 8);
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
    EXPECT_TRUE(texto.find(sub) != string::npos);
}

TEST(PalindromoTest, PalindromoAlInicio)
{
    string texto = "racecarxxx";
    auto [start, end, sub] = encontrarPalindromoMasLargo(texto);
    EXPECT_EQ(sub, "racecar");
    EXPECT_EQ(start, 1);
    EXPECT_EQ(end, 7);
}

TEST(PalindromoTest, PalindromoAlFinal)
{
    string texto = "xxxracecar";
    auto [start, end, sub] = encontrarPalindromoMasLargo(texto);
    EXPECT_EQ(sub, "racecar");
    EXPECT_EQ(start, 4);
    EXPECT_EQ(end, 10);
}
