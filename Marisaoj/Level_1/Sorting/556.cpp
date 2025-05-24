#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].fi;
    for(int i = 0; i < n; i++)
        cin >> a[i].se;
    sort(all(a));
    priority_queue<int, vector<int>, greater<int>> pq;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i].fi > pq.size())
            pq.push(a[i].se);
        else if(pq.top() < a[i].se){
            ans += pq.top();
            pq.pop();
            pq.push(a[i].se);
        }
        else
            ans += a[i].se;
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