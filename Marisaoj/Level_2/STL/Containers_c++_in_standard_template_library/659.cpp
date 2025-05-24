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

const int maxn = 2e5+6;
int n, m;
vector<pii> a;

void solve(){
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(all(a));
    priority_queue<int> pq;
    int ans = 0;
    ll time = 0;
    for (int i = 0; i < n; i++) {
        time += a[i].se;
        pq.push(a[i].se);
        time += i ? a[i].fi-a[i-1].fi : a[i].fi;
        while (!pq.empty() && time > m) {
            time -= pq.top();
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
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