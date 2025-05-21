#include <iostream>
#include "utils.h"
#include "analizador.h"

using namespace std;

string sinSaltos(const string &str)
{
    string res = str;
    res.erase(remove(res.begin(), res.end(), '\n'), res.end());
    return res;
}

void verificarYMostrar(const string &transmissionOriginal, const string &mcodeOriginal)
{
    string transmissionLower = toLower(transmissionOriginal);
    string mcodeLower = toLower(mcodeOriginal);

    int pos;
    bool encontrado = buscarCodigo(transmissionLower, mcodeLower, pos);
    if (encontrado)
        cout << "true " << (pos + 1) << endl;
    else
        cout << "false" << endl;
}

int main()
{
    string t1 = leerArchivo("data/transmission1.txt");
    string t2 = leerArchivo("data/transmission2.txt");
    string m1 = leerArchivo("data/mcode1.txt");
    string m2 = leerArchivo("data/mcode2.txt");
    string m3 = leerArchivo("data/mcode3.txt");

    // Parte 1: búsqueda de códigos
    verificarYMostrar(t1, m1);
    verificarYMostrar(t1, m2);
    verificarYMostrar(t1, m3);
    verificarYMostrar(t2, m1);
    verificarYMostrar(t2, m2);
    verificarYMostrar(t2, m3);

    // Parte 2: palíndromos
    auto [start1, end1, pal1] = encontrarPalindromoMasLargo(t1);
    auto [start2, end2, pal2] = encontrarPalindromoMasLargo(t2);
    cout << start1 << " " << end1 << " " << sinSaltos(pal1) << endl;
    cout << start2 << " " << end2 << " " << sinSaltos(pal2) << endl;

    // Parte 3: substring común más largo
    auto [commonStart, commonEnd, substringComun] = substringComunMasLargo(t1, t2);
    cout << commonStart << " " << commonEnd << " " << substringComun;

    return 0;
}
