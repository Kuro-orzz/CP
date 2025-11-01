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
    int n, q; cin >> n >> q;
    vector<int> a(n), l(q, 1), r(q, n), ans(q, -1);
    vector<pii> query(q);
    vector<vector<int>> pos(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 0; i < q; i++) cin >> query[i].fi >> query[i].se;

    Fenwick<int> bit(n+1);

    while (true) {
        vector<vector<int>> candidate(n+1);
        bool answered = true;
        for (int i = 0; i < q; i++) {
            if (l[i] <= r[i]) {
                answered = false;
                candidate[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if (answered) break;

        bit.reset();
        for (int mid = n; mid >= 1; mid--) {
            for (int x : pos[mid]) bit.update(x+1, 1);
            for (int id : candidate[mid]) {
                if (bit.get(query[id].fi, query[id].se) >= mid) {
                    ans[id] = mid;
                    l[id] = mid + 1;
                } else {
                    r[id] = mid - 1;
                }
            }
        }
    }
    for (int x : ans) cout << x << '\n';
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