#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    // while (cin >> s)
    // {
    cin >> s;
    int record[3] = {0};
    double n = 0;
    for (char x : s)
    {
        if (x == '0')
        {
            n += (record[2] + 1) * (record[1] * 2 + record[2]) / 2;
            record[0] += 1;
        }
        else if (x == '1')
        {
            record[1] += 1;
        }
        else if (x == '?')
        {
            n += n + (record[2] + 1) * (record[1] * 2 + record[2]) / 2;
            record[2] += 1;
        }
    }
    cout << n << endl;
    // }
    return 0;
}