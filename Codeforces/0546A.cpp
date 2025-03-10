#include <iostream>
using namespace std;

void solve()
{
    int k, n, w;
    cin >> k >> n >> w;
    for(int i = 1; i <= w; i++)
        n-=i*k;
    if (n < 0)
        cout << -n;
    else
        cout << 0;
}

int main()
{
    solve();
    return 0;
}