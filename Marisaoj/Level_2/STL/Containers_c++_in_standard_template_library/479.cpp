#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int q;
ordered_set s;

void solve(){
    cin >> q;
    while (q--) {
        int tv; cin >> tv;
        if (tv == 1) {
            int x; cin >> x;
            int idx = s.order_of_key(x);
            if (*s.find_by_order(idx) != x) {
                s.insert(x);
            }
            else {
                s.erase(x);
            }
        }
        else {
            int n = s.size();
            if (n % 2) {
                cout << *s.find_by_order(n/2) << '\n';
            }
            else {
                double ans = (*s.find_by_order(n/2-1) + *s.find_by_order(n/2)) / 2.0;
                if (ans != (int)ans)
                    cout << fixed << setprecision(1) << ans << '\n';
                else
                    cout << (int)ans << '\n';
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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