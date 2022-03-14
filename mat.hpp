#ifndef MAT_INCLUDED
#define MAT_INCLUDED

#include <string>
using namespace std;

namespace ariel
{
    string even(char c1, char c2, int times, int cols);
    string odd(char c1, char c2, int times, int cols);
    string mat(int col, int row, char c1, char c2);
}

#endif // MAT_INCLUDED