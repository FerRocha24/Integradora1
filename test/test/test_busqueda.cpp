#include <string>
#include <fstream>
#include <cstdio>
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
    EXPECT_FALSE(buscarCodigo(texto, codigo, pos));
}

TEST(ArchivoTest, LeeContenidoCorrecto)
{
    std::ofstream archivo("archivo_prueba.txt");
    archivo << "Linea1\nLinea2\n";
    archivo.close();

    std::string contenido = leerArchivo("archivo_prueba.txt");
    EXPECT_NE(contenido.find("Linea1"), std::string::npos);
    EXPECT_NE(contenido.find("Linea2"), std::string::npos);

    std::remove("archivo_prueba.txt");
}
