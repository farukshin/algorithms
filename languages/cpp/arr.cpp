#include <iostream>
using namespace std;

int main()
{
    int x[2];             // {0, 0}
    int a[2] = {1, 2};    // {1, 2}
    cout << a[1] << '\n'; // 2
    for (int i = 0; i < 2; i++)
    {
        cout << a[i]; // 1 2
    }
    for (int n : a)
    {
        cout << n; // 1 2
    }

    return 0;
}