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

vector<int> vis, back_to_one, path, ans;
vector<vector<pii>> a;
int n, k;
int cur_d = 0, dist = INT_MAX;

void backtrack(int idx, int k) {
    if (k == 1) {
        if (cur_d + back_to_one[idx] < dist) {
            dist = cur_d + back_to_one[idx];
            ans = path;
            ans.push_back(idx);
        }
        return;
    }
    vis[idx] = 1;
    path.push_back(idx);
    for (int i = 1; i <= n; i++) {
        if (vis[a[idx][i].se]) continue;
        cur_d += a[idx][i].fi;
        if (cur_d + k - 1 < dist) backtrack(a[idx][i].se, k-1);
        cur_d -= a[idx][i].fi;
    }
    vis[idx] = 0;
    path.pop_back();
}

void solve() {
    cin >> n >> k;
    vis.resize(n+1, 0);
    a.resize(n+1, vector<pii>(n+1));
    back_to_one.resize(n+1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j].fi;
            a[i][j].se = j;
        }
        back_to_one[i] = a[i][1].fi;
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin()+1, a[i].end(), greater<pii>());
    }
    backtrack(1, k);
    cout << dist << '\n';
    for(auto it : ans) cout << it << ' ';
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