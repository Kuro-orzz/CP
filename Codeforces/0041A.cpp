#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s2.begin(),s2.end());
    if (s1 == s2)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    solve();
    return 0;
}