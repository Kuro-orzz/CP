/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, typename Compare = std::less<T>>
using ordered_set = tree<
    T,
    null_type,
    Compare,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

ordered_set<pii> os;
map<int, vector<int>> mp;

void solve() {
    int t; cin >> t;
    while (t--) {
    	string s; cin >> s;
        if (s == "IN") {
            int x; cin >> x;
            os.insert({x, t});
            mp[x].push_back(t);
        } else if (s == "OUT") {
            int x; cin >> x;
            os.erase({x, mp[x].back()});
            mp[x].pop_back();
        } else if (s == "MEDIAN") {
            int sz = os.size();
            if (sz % 2) {
                cout << (*os.find_by_order(sz / 2)).fi << '\n';
            } else {
                int i = (*os.find_by_order(sz / 2 - 1)).fi;
                int j = (*os.find_by_order(sz / 2)).fi;
                cout << (i + j) / 2.0 << '\n';
            }
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