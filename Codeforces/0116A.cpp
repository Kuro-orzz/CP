#include <iostream>
using namespace std;

void solve()
{
    int n; cin >> n;
    int capacity = 0;
    int res = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        res-=x;
        res+=y;
        if (res > capacity)
            capacity = res;
    }
    cout << capacity;
}

int main()
{
    solve();
    return 0;
}