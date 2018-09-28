#include <stdio.h>
#include <iostream>
using namespace std;
#include <math.h>
int main()
{
    long double i;
    int x = 0;
    while (cin >> i)
    {
        x++;
        printf("Case %d: %d\n", x, (int)ceil(log(3 * pow(1.5, i)) / log(10.0)));
    }
}
