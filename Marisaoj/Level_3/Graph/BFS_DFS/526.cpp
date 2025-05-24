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

const int N = 5e2 + 6;
int n, m;
char a[N][N];
bool vis[N][N];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool check = false;
int cnt = 0;

bool isValid(pii u) {
    return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
}

void dfs(pii u) {
    cnt++;
    vis[u.fi][u.se] = 1;
    for (int i = 0; i < 4; i++) {
        pii v = {u.fi + dx[i], u.se + dy[i]};
        if (isValid(v) && !vis[v.fi][v.se]) {
            if (a[v.fi][v.se] == '.') check = true;
            if (a[v.fi][v.se] == 'W') dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && a[i][j] == 'W') {
                check = false;
                cnt = 0;
                dfs({i, j});
                if (!check) ans += cnt;
            }
        }
    }
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