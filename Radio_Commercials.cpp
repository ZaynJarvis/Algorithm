#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, P;
    cin >> N >> P;
    int s = 0;
    int d = 0;
    int min = 0, max = 0;
    while (N--)
    {
        int x;
        cin >> x;
        s += (x - P);
        if (s < min)
        {
            min = s;
            max = min;
        }
        else if (s > max)
        {
            max = s;
            if (max - min > d)
                d = (max - min);
        }
    }
    cout << d;
    return 0;
}
