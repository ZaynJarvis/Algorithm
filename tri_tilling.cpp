#include <iostream>
#include <math.h>
#include <vector>
// #include <string>
using namespace std;

int f(int n, int s);

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
            break;
        cout << f(n, 0) << endl;
    }
    return 0;
}

int f(int n, int s)
{
    if (s == 0)

        if (n == 0)
            return 1;
        else if (n == 1)
            return 0;
        else
            return 3 * f(n - 2, 0) + 2 * f(n - 2, 1);
    else
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 0;
        else
            return f(n - 2, 0) + f(n - 2, 1);
    }
}