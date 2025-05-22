

/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include "utils.h"
#include <string>
#include <tuple>
#include <vector>
#include <fstream>

inline std::string leerArchivo(const std::string &nombre)
{
  std::ifstream archivo(nombre);
  std::string linea, contenido;
  while (std::getline(archivo, linea))
  {
    contenido += linea + "\n";
  }
  return contenido;
}

inline bool buscarCodigo(const std::string &transmission, const std::string &mcode, int &posicion)
{
  posicion = transmission.find(mcode);
  return posicion != std::string::npos;
}

inline std::tuple<int, int, std::string> encontrarPalindromoMasLargo(const std::string &texto)
{
  int maxLen = 0, inicio = 0;
  int n = texto.size();

  for (int i = 0; i < n; ++i)
  {
    int l = i, r = i;
    while (l >= 0 && r < n && texto[l] == texto[r])
    {
      if (r - l + 1 > maxLen)
      {
        maxLen = r - l + 1;
        inicio = l;
      }
      --l;
      ++r;
    }

    l = i;
    r = i + 1;
    while (l >= 0 && r < n && texto[l] == texto[r])
    {
      if (r - l + 1 > maxLen)
      {
        maxLen = r - l + 1;
        inicio = l;
      }
      --l;
      ++r;
    }
  }

  return std::make_tuple(inicio + 1, inicio + maxLen, texto.substr(inicio, maxLen));
}

inline std::tuple<int, int, std::string> substringComunMasLargo(const std::string &a, const std::string &b)
{
  int m = a.size(), n = b.size();
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
  int maxLen = 0, endIdx = 0;

  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > maxLen)
        {
          maxLen = dp[i][j];
          endIdx = i;
        }
      }

  return std::make_tuple(endIdx - maxLen + 1, endIdx, a.substr(endIdx - maxLen, maxLen));
}

#endif
