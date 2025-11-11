/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "Uphold integrity and ethics throughout the contest.";
    } else if (n == 2) {
        cout << "Do not seek or receive external help from people, platforms, tools or AI.";
    } else if (n == 3) {
        cout << "Follow all ICPC rules and guidelines, accept decisions made by organizers and judges as final.";
    } else if (n == 4) {
        cout << "Show good sportmanship and treat competitors, volunteers, staff and judges with respect.";
    } else if (n == 5) {
        cout << " Compete with creativity and teamwork, honor the contest spirit and pursue excellence.";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
