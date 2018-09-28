#include <iostream>
#include <vector>
using namespace std;
int f(vector<int> arr);
int main()
{
    int a;
    cin >> a;
    int x = 0;
    vector<int> arr;
    while ((a - x++))
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }
    cout << f(arr) << endl;
}

int f(vector<int> arr)
{
    if (arr.size() == 1)
        return 1;
    else
    {
        int back = arr.back();
        arr.pop_back();
        if (back > arr.back())
            return 1 + f(arr);
        else
            return f(arr);
    }
}
