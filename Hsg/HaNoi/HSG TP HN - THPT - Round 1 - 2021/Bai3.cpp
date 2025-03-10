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
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++)
        mp[a[i].fi] = mp[a[i].se] = 0;
    for(int i = 0; i < n; i++){
        mp[a[i].fi]++;
        mp[a[i].se+1]--;
    }
    ll sum = 0;
    for(auto &it : mp){
        sum += it.se;
        it.se = sum;
    }
    ll ans = 0, l = 0, r = 0;
    for(auto it : mp){
        if(!l && it.se == k)
            l = it.fi;
        if(it.se != k){
            if(l && r){
                ans += it.fi-l;
                l = r = 0;
            }
        }
        else
            r = it.fi;
    }
    if(l && r) ans += r-l+1;
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    freopen("DC.INP", "r", stdin);
    freopen("DC.OUT", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
