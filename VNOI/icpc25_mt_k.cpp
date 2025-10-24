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

void ask(int i) {
    cout << "? " << i << endl;
}

void ans(vector<int> a) {
    cout << "! ";
    for (int x : a) cout << x << ' ';
    cout << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> a(6), row(n), vis(7);
    iota(all(row), 0);
    for (int i = 0; i < 6; i++) {
        map<int, vector<int>> mp;
        for (int x : row) {
            ask(6 * x + i + 1);
            int color; cin >> color;
            mp[color].push_back(x);
        }
        int mn = -1;
        for (int j = 1; j <= 6; j++) {
            if (mn == -1 && !vis[j]) mn = j;
        }
        for (int j = 1; j <= 6; j++) {
            if (mn == -1 && !vis[j]) mn = j;
            else if (mp[j].size() < mp[mn].size() && !vis[j]) {
                mn = j;
            }
        }
        row = mp[mn];
        a[i] = mn;
        vis[mn] = 1;
    }
    ans(a);
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        // freopen(TASK ".inp", "r", stdin);
        // freopen(TASK ".out", "w", stdout);
    }
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}