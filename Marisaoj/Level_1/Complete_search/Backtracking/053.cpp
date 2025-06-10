#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
 
const int N = 10;
int n, a[N][N], ans = 0;

bool check(pii u) {
    if (u == make_pair(-1, -1)) return true;
    auto [x, y] = u;
    auto check_same_row = [&]() -> bool {
        for (int j = 0; j < n; j++) {
            if (j != y && a[x][j]) return false;
        }
        return true;
    };
    auto check_same_col = [&]() -> bool {
        for (int i = 0; i < n; i++) {
            if (i != x && a[i][y]) return false;
        }
        return true;
    };
    auto check_diagonal = [&]() -> bool {
        pii t = {x, y};
        while (t.fi < n && t.se < n) {
            if (t.fi != x && a[t.fi][t.se]) return false;
            t.fi++, t.se++;
        }
        t = {x, y};
        while (t.fi >= 0 && t.se >= 0) {
            if (t.fi != x && a[t.fi][t.se]) return false;
            t.fi--, t.se--;
        }
        t = {x, y};
        while (t.fi >= 0 && t.se < n) {
            if (t.fi != x && a[t.fi][t.se]) return false;
            t.fi--, t.se++;
        }
        t = {x, y};
        while (t.fi < n && t.se >= 0) {
            if (t.fi != x && a[t.fi][t.se]) return false;
            t.fi++, t.se--;
        }
        return true;
    };
    return check_same_row() && check_same_col() && check_diagonal();
}

void backtrack(pii prev, int row) {
    if (!check(prev)) return;
    if (row == n) {
        ans++;
        return;
    }
    for (int j = 0; j < n; j++) {
        a[row][j] = 1;
        backtrack({row, j}, row+1);
        a[row][j] = 0;
    }
}

void solve(){
    cin >> n;
    backtrack({-1, -1}, 0);
    cout << ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}