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
    int n, d; cin >> n >> d;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    mp[0]++;
    ll cur = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cur += a[i];
        cur %= d;
        cur = (cur+d)%d;
        ans += mp[cur];
        mp[cur]++;
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