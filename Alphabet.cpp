#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int arr[50];
    int k = 50;
    while (k--)
    {
        arr[k] = 1;
    }

    int max = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int j = i - 1;
        int m = i;
        while (j >= 0)
        {
            if ((s[i] > s[j]) && (m == i))
                m = j;
            else if ((s[i] > s[j]) && (arr[m] < arr[j]))
                m = j;
            j--;
        }
        if (m != i)
            arr[i] = arr[m] + 1;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    cout << 26 - max << endl;

    return 0;
}