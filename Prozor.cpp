#include <iostream>
using namespace std;
int main()
{
    int m, n, p;
    cin >> m >> n >> p;
    string arr[100];
    int numArr[100][100] = {0};
    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        arr[i] = x;
    }

    for (int i = 0; i < m - p + 1; i++)
    {
        for (int j = 0; j < n - p + 1; j++)
        {
            for (int a = i + 1; a < i + p - 1; a++)
                for (int b = j + 1; b < j + p - 1; b++)
                    if (arr[a][b] == '*')
                        numArr[i][j]++;
        }
    }
    int max = 0;
    int index[2];
    for (int i = 0; i < m - p + 1; i++)
    {
        for (int j = 0; j < n - p + 1; j++)
        {
            if (numArr[i][j] > max)
            {
                max = numArr[i][j];
                index[0] = i;
                index[1] = j;
            }
        }
    }
    arr[index[0]][index[1]] = '+';
    arr[index[0] + p - 1][index[1]] = '+';
    arr[index[0]][index[1] + p - 1] = '+';
    arr[index[0] + p - 1][index[1] + p - 1] = '+';

    for (int i = index[0] + 1; i < index[0] + p - 1; i++)
    {
        arr[i][index[1]] = '|';
        arr[i][index[1] + p - 1] = '|';
    }
    for (int j = index[1] + 1; j < index[1] + p - 1; j++)
    {
        arr[index[0]][j] = '-';
        arr[index[0] + p - 1][j] = '-';
    }

    // int x = 1, y = 1;
    // while (x++ < m)
    // {
    //     while (y++ < n)
    //         cout << arr[x][y];
    //     cout << endl;
    // }
    cout << max << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}