#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    ll n, x; cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    ll ans = 0;
    ll l = 0, r = 1e18;
    while(l <= r){
        ll mid = (l+r)>>1;
        ll cnt = 0;
        for(int i = 0; i < n; i++)
            if(mid >= a[i].fi)
                cnt += (mid-a[i].fi)/a[i].se+1;
        if(cnt >= x){
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
