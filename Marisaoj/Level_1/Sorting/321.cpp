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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    if(n == 1){
        cout << a[0]+b[0];
        return;
    }
    pair<ll, ll> k = {a[n/2-1]+a[n/2], b[n/2-1]+b[n/2]};
    k = {k.fi/2, k.se/2};
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += abs(a[i]-k.fi)+abs(b[i]-k.se);
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