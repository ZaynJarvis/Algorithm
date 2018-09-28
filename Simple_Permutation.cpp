#include <iostream>
int main()
{
    int n = 5;
    for (int subset = 0; subset < (1 << n); subset++)
    {
        for (int i = 0; i < n; i++) // 0 1 2 3 4
        {
            if ((subset & (1 << i)) != 0)
            {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    }
}
