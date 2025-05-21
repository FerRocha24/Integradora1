
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <math.h>
#include <stdexcept>

/**
  metodo para realizar divisiones de dos numeros
 */
double divide(int x, int y)
{
    if (y != 0)
        return x / y;
    else
        return 0;
}
