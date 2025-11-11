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
    map<pii, char> block;
    Fenwick<ll> BIT(3e5+6), cnt(3e5+6);
    
    block[{1, n}] = 'A';
    BIT.update(n, n);
    cnt.update(n, 1);

    while (q--) {
        int tv; cin >> tv;
        if (tv == 1) {
            int l, r; cin >> l >> r;
            char c; cin >> c;
            l++; r++;
            
            vector<pair<pii, char>> merge;
            auto ptr = block.lower_bound({l, -1});
            if (ptr != block.begin()) ptr = prev(ptr);
            while (ptr != block.end() && ptr->fi.se >= l-1 && ptr->fi.fi <= r+1) {
                merge.push_back({ptr->fi, ptr->se});
                ptr = next(ptr);
            }
            char prev_blk = block[merge[0].fi];
            char next_blk = block[merge.back().fi];
            // cout << merge[0].fi.fi << ' ' << merge[0].fi.se << '\n';
            // cout << merge.back().fi.fi << ' ' << merge.back().fi.se << '\n';
            // cout << prev_blk << ' ' << next_blk << '\n';
            for (auto it : merge) {
                block.erase(it.fi);
                BIT.update(it.fi.se - it.fi.fi + 1, -(it.fi.se - it.fi.fi + 1));
                cnt.update(it.fi.se - it.fi.fi + 1, -1);
            }

            if (prev_blk == c && next_blk != c) {
                l = merge[0].fi.fi;
                block[{l, r}] = c;
                BIT.update(r-l+1, r-l+1);
                cnt.update(r-l+1, 1);
                if (r < merge.back().fi.se) {
                    block[{r+1, merge.back().fi.se}] = next_blk;
                    BIT.update(merge.back().fi.se-r, merge.back().fi.se-r);
                    cnt.update(merge.back().fi.se-r, 1);
                }
            } else if (prev_blk != c && next_blk == c) {
                if (merge[0].fi.fi < l) {
                    block[{merge[0].fi.fi, l-1}] = prev_blk;
                    BIT.update(l-merge[0].fi.fi, l-merge[0].fi.fi);
                    cnt.update(l-merge[0].fi.fi, 1);
                }
                r = merge.back().fi.se;
                block[{l, r}] = c;
                BIT.update(r-l+1, r-l+1);
                cnt.update(r-l+1, 1);
            } else if (prev_blk == c && next_blk == c) {
                l = merge[0].fi.fi;
                r = merge.back().fi.se;
                block[{l, r}] = c;
                BIT.update(r-l+1, r-l+1);
                cnt.update(r-l+1, 1);
            } else if (prev_blk != c && next_blk != c) {
                if (merge[0].fi.fi < l) {
                    block[{merge[0].fi.fi, l-1}] = prev_blk;
                    BIT.update(l-merge[0].fi.fi, l-merge[0].fi.fi);
                    cnt.update(l-merge[0].fi.fi, 1);
                }
                block[{l, r}] = c;
                BIT.update(r-l+1 ,r-l+1);
                cnt.update(r-l+1, 1);
                if (r < merge.back().fi.se) {
                    block[{r+1, merge.back().fi.se}] = next_blk;
                    BIT.update(merge.back().fi.se-r, merge.back().fi.se-r);
                    cnt.update(merge.back().fi.se-r, 1);
                }
            }
        } else if (tv == 2) {
            int k; cin >> k;
            cout << BIT.get(k+1, 3e5) - cnt.get(k+1, 3e5) * k << '\n';
        }
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
