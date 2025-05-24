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

int n;
set<int> s;
multiset<int> ms;

void solve(){
    cin >> n;
    while (n--) {
        int x; cin >> x;
        if (s.count(x)) {
            if (x != *s.begin()) {
                int dist = x-*prev(s.find(x));
                ms.erase(ms.find(dist));
            }
            if (x != *s.rbegin()) {
                int dist = *next(s.find(x))-x;
                ms.erase(ms.find(dist));
            }
            s.erase(x);
        }
        else {
            s.insert(x);
        }
        auto it = s.find(x);
        if (it != s.end()) {
            if (it != s.begin())
                ms.insert(*it-*prev(it));
            if (*it != *s.rbegin()) {
                ms.insert(*next(it)-*it);
            }
        }
        if (s.size() < 2) {
            cout << -1 << '\n';
        }
        else {
            cout << *ms.begin() << '\n';
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