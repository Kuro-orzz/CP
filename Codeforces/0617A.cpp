#include <iostream>
using namespace std;

void solve()
{
    int x; cin >> x;
    if (x % 5 == 0)
        cout << x/5;
    else
        cout << x/5 +1;
}

int main()
{
    solve();
    return 0;
}