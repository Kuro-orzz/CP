#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    string s, x;
    cin >> s;
    x = "hello";
    int cnt=0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == x[cnt])
            cnt++;
        if (cnt == 5){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main()
{
    solve();
    return 0;
}