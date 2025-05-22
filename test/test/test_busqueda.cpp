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

TEST(ArchivoTest, LeerArchivoConContenido)
{
    std::ofstream archivo("temp_test.txt");
    archivo << "Linea1\nLinea2\n";
    archivo.close();

    std::string contenido = leerArchivo("temp_test.txt");
    EXPECT_NE(contenido.find("Linea1"), std::string::npos);
    EXPECT_NE(contenido.find("Linea2"), std::string::npos);

    std::remove("temp_test.txt");
}

TEST(ArchivoTest, LeerArchivoVacio)
{
    std::ofstream archivo("archivo_vacio.txt");
    archivo.close();

    std::string contenido = leerArchivo("archivo_vacio.txt");
    EXPECT_TRUE(contenido.empty());

    std::remove("archivo_vacio.txt");
}

TEST(ArchivoTest, LeerArchivoUnaLinea)
{
    std::ofstream archivo("una_linea.txt");
    archivo << "SoloUnaLinea";
    archivo.close();

    std::string contenido = leerArchivo("una_linea.txt");
    EXPECT_EQ(contenido, "SoloUnaLinea\n");

    std::remove("una_linea.txt");
}

TEST(ArchivoTest, LeerArchivoNoExiste)
{
    std::string contenido = leerArchivo("archivo_que_no_existe.txt");
    EXPECT_TRUE(contenido.empty());
}

TEST(ArchivoTest, LeerArchivosExistentes)
{
    std::vector<std::string> archivos = {
        "transmission1.txt",
        "transmission2.txt",
        "mcode1.txt",
        "mcode2.txt",
        "mcode3.txt"};

    for (const auto &archivo : archivos)
    {
        std::string contenido = leerArchivo(archivo);
        EXPECT_FALSE(contenido.empty()) << "Archivo vacío o no leído: " << archivo;
    }
}
