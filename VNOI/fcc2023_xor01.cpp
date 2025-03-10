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
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[a[i]]++;
    ll ans = 0;
    for(auto it : mp){
        if(it.fi % 2 && mp.count(it.fi-1))
            continue;
        int t = it.se;
        if(it.fi % 2 == 0 && mp.count(it.fi+1))
            t += mp[it.fi+1];
        if(t > 1)
            ans += 1ll*(t-1)*t/2;
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
