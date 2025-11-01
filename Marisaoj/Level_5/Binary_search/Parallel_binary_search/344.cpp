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
#define unique(x) x.erase(unique(all(x)), x.end())

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

struct Query {
    int l, r, w;
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1), l(n+1, 1), r(n+1, q), ans(n+1, -1);
    vector<Query> query(q+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) cin >> query[i].l >> query[i].r >> query[i].w;

    Fenwick<int> bit(n+1);

    while (true) {
        vector<vector<int>> candidate(max(n, q)+1);
        bool answered = true;
        for (int i = 1; i <= n; i++) {
            if (l[i] <= r[i]) {
                answered = false;
                candidate[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if (answered) break;

        bit.reset();
        for (int mid = 1; mid <= q; mid++) {
            bit.update_range(query[mid].l, query[mid].r, query[mid].w);
            for (int id : candidate[mid]) {
                if (bit.get(id) >= a[id]) {
                    ans[id] = mid;
                    r[id] = mid - 1;
                } else {
                    l[id] = mid + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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
