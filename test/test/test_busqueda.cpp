#include <string>
#include <fstream>
#include "analizador.h"
#include "gtest/gtest.h"

using std::string;

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
    bool encontrado = buscarCodigo(texto, codigo, pos);
    EXPECT_FALSE(encontrado);
}

TEST(BusquedaTest, CodigoAlInicio)
{
    string texto = "abcxyz";
    string codigo = "abc";
    int pos;
    bool encontrado = buscarCodigo(texto, codigo, pos);
    EXPECT_TRUE(encontrado);
    EXPECT_EQ(pos, 0);
}

TEST(ArchivoTest, LeeArchivoDeTransmision)
{
    string contenido = leerArchivo("transmission1.txt");

    EXPECT_FALSE(contenido.empty());

    EXPECT_NE(contenido.find("MCODE"), string::npos);
}
