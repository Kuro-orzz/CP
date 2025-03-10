#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll cal(int l, int r){
    return 1ll*(r-l+1)*(l+r)/2;
}

void solve(){
    int l, r; cin >> l >> r;
    ll sum = cal(l, r);
    int ans = 0;
    ll mn = LLONG_MAX;
    int low = l, high = r;
    while(low <= high){
        int m = (low+high)>>1;
        if(abs(cal(l, m)-cal(m+1, r)) < mn){
            mn = abs(cal(l, m)-cal(m+1, r));
            ans = m;
        }
        if(cal(l, m) < cal(m+1, r)) low = m+1;
        else high = m-1; 
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
