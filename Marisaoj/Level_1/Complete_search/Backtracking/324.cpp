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
 
const int N = 7;
int n, m, ans[N][N];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
bool solved = false;

bool isValid(pii u) {
    return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
}

void dfs(pii u, int cnt) {
    ans[u.fi][u.se] = cnt;
    if (cnt == n*m) {
        solved = true;
        return;
    }
    for (int i = 0; i < 8; i++) {
        pii v = {u.fi + dx[i], u.se + dy[i]};
        if (isValid(v) && !ans[v.fi][v.se]) dfs(v, cnt+1);
        if (solved) return;
    }
    ans[u.fi][u.se] = 0;
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs({i, j}, 1);
            if (solved) goto skip;
        }
    }
    skip:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
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