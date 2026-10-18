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

/* ---------- 3D difference (range add -> point value) ---------- */
vector<vector<vector<ll>>> diff_3d_init(int n, int m, int p) {
    return vector<vector<vector<ll>>>(n+2, vector<vector<ll>>(m+2, vector<ll>(p+2)));
}

void diff_3d_add(vector<vector<vector<ll>>> &d,
                 int x1, int y1, int z1, int x2, int y2, int z2, ll v) {
    d[x1][y1][z1]       += v;
    d[x2+1][y1][z1]     -= v;
    d[x1][y2+1][z1]     -= v;
    d[x1][y1][z2+1]     -= v;
    d[x2+1][y2+1][z1]   += v;
    d[x2+1][y1][z2+1]   += v;
    d[x1][y2+1][z2+1]   += v;
    d[x2+1][y2+1][z2+1] -= v;
}

void diff_3d_build(vector<vector<vector<ll>>> &d, int n, int m, int p) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= p; k++) {
                d[i][j][k] += d[i-1][j][k] + d[i][j-1][k] + d[i][j][k-1]
                            - d[i-1][j-1][k] - d[i-1][j][k-1] - d[i][j-1][k-1]
                            + d[i-1][j-1][k-1];
            }
        }
    }
}

void solve() {
    int n, m, p, Q, L; cin >> n >> m >> p >> Q >> L;

    auto c0 = diff_3d_init(n, m, p);
    auto cx = diff_3d_init(n, m, p);
    auto cy = diff_3d_init(n, m, p);
    auto cz = diff_3d_init(n, m, p);

    for (int q = 0; q < Q; q++) {
        int x1, y1, z1, x2, y2, z2; ll S, A, B, C;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> S >> A >> B >> C;
        ll K0 = S - A*x1 - B*y1 - C*z1;
        diff_3d_add(c0, x1, y1, z1, x2, y2, z2, K0);
        diff_3d_add(cx, x1, y1, z1, x2, y2, z2, A);
        diff_3d_add(cy, x1, y1, z1, x2, y2, z2, B);
        diff_3d_add(cz, x1, y1, z1, x2, y2, z2, C);
    }

    diff_3d_build(c0, n, m, p);
    diff_3d_build(cx, n, m, p);
    diff_3d_build(cy, n, m, p);
    diff_3d_build(cz, n, m, p);

    string out;
    for (int i = 0; i < L; i++) {
        int x, y, z; cin >> x >> y >> z;
        ll ans = c0[x][y][z] + cx[x][y][z]*x + cy[x][y][z]*y + cz[x][y][z]*z;
        out += to_string(ans);
        out += '\n';
    }
    cout << out;
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