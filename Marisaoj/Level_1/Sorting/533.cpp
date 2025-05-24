#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct cmp{
    bool operator()(pii a, pii b){
        return a.fi+a.se < b.fi+b.se;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    priority_queue<pii, vector<pii>, cmp> pq;
    for(int i = 0; i < n; i++)
        pq.push(a[i]);
    ll ans = 0;
    for(int i = 0; i < min(n, q); i++){
        ans += pq.top().fi+pq.top().se;
        pq.push({0, pq.top().se});
        pq.pop();
    }
    ans += 1ll*max(0, q-n)*pq.top().se;
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