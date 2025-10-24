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

template <typename T>
struct Fenwick{
    int n;
    vector<T> fen;

    Fenwick(int _n): n(_n), fen(_n+1) {}

    void update(int pos, T val) {
        for (; pos <= n; pos += pos & -pos) {
            fen[pos] += val;
        }
    }

    T get(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= pos & -pos) {
            ans += fen[pos];
        }
        return ans;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    void update_range(int l, int r, T val){
        update(l, val);
        update(r+1, -val);
    }

    void reset() {
        fill(all(fen), T(0));
    }
};

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int BLOCK_SIZE = ((int)sqrt(n), 500);
    int max_val = 5e4 + 6;
    vector<Fenwick<int>> BIT(n / BLOCK_SIZE + 2, Fenwick<int>(max_val));
    Fenwick<int> fen(max_val);
    ll inv = 0;
    for (int i = 0; i < n; i++) {
        int blk = i / BLOCK_SIZE;
        BIT[blk].update(a[i], 1);
        inv += i - fen.get(a[i]);
        fen.update(a[i], 1);
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        x--;
        int blk = x / BLOCK_SIZE;

        // Before blk
        for (int i = 0; i < blk; i++) {
            inv -= BIT[i].get(max_val) - BIT[i].get(a[x]);
            inv += BIT[i].get(max_val) - BIT[i].get(y);
        }
        // Block blk
        for (int i = blk * BLOCK_SIZE; i < min(n, (blk+1) * BLOCK_SIZE); i++) {
            if (i < x) {
                inv -= a[i] > a[x];
                inv += a[i] > y;
            } else if (i > x) {
                inv -= a[x] > a[i];
                inv += y > a[i];
            }
        }
        // After blk
        for (int i = blk+1; i < BIT.size(); i++) {
            inv -= BIT[i].get(a[x]-1);
            inv += BIT[i].get(y-1);
        }

        BIT[blk].update(a[x], -1);
        a[x] = y;
        BIT[blk].update(y, 1);

        cout << inv << '\n';
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