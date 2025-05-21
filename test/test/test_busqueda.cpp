#include <gtest/gtest.h>
#include "../analizador.h"

TEST(BusquedaTest, CodigoPresente)
{
    string texto = "abc123xyz";
    string codigo = "123";
    int pos;
    bool encontrado = buscarCodigo(texto, codigo, pos);
    EXPECT_TRUE(encontrado);
    EXPECT_EQ(pos, 3);
}

TEST(BusquedaTest, CodigoAusente)
{
    string texto = "abcdef";
    string codigo = "xyz";
    int pos;
    EXPECT_FALSE(buscarCodigo(texto, codigo, pos));
}
