#include <string>
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
    string texto = "inicio123";
    string codigo = "inicio";
    int pos;
    bool encontrado = buscarCodigo(texto, codigo, pos);
    EXPECT_TRUE(encontrado);
    EXPECT_EQ(pos, 0);
}

TEST(BusquedaTest, CodigoAlFinal)
{
    string texto = "abcdeFinal";
    string codigo = "Final";
    int pos;
    bool encontrado = buscarCodigo(texto, codigo, pos);
    EXPECT_TRUE(encontrado);
    EXPECT_EQ(pos, texto.size() - codigo.size());
}

TEST(BusquedaTest, CodigoIgualTexto)
{
    string texto = "completo";
    string codigo = "completo";
    int pos;
    EXPECT_TRUE(buscarCodigo(texto, codigo, pos));
    EXPECT_EQ(pos, 0);
}

TEST(BusquedaTest, CodigoVacio)
{
    string texto = "abcdefg";
    string codigo = "";
    int pos;
    EXPECT_TRUE(buscarCodigo(texto, codigo, pos)); // .find("") siempre retorna 0
    EXPECT_EQ(pos, 0);
}

TEST(BusquedaTest, TextoVacio)
{
    string texto = "";
    string codigo = "123";
    int pos;
    EXPECT_FALSE(buscarCodigo(texto, codigo, pos));
}

TEST(BusquedaTest, AmbosVacios)
{
    string texto = "";
    string codigo = "";
    int pos;
    EXPECT_TRUE(buscarCodigo(texto, codigo, pos));
    EXPECT_EQ(pos, 0);
}
