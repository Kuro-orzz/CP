#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
int q;
map<ll, ll> mp;
set<pair<ll, ll>> cnt;
 
void del(ll val, ll fre){
    if(cnt.count({fre, val}))
        cnt.erase({fre, val});
}
 
void ins(ll val, ll fre){
    cnt.insert({fre, val});
}
 
void solve(){
    cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            ll x, a; cin >> x >> a;
            del(x, mp[x]);
            mp[x] += a;
            ins(x, mp[x]);
        }
        else if(type == 2){
            ll x, b; cin >> x >> b;
            del(x, mp[x]);
            mp[x] -= b;
            if(mp[x] <= 0) mp.erase(x);
            else ins(x, mp[x]);
        }
        else if(type == 3){
            cout << (*mp.begin()).fi << '\n';
        }
        else if(type == 4){
            cout << (*mp.rbegin()).fi << '\n';
        }
        else if(type == 5){
            ll y; cin >> y;
            ll ans = 0;
            if(mp.empty()){
                cout << 0 << '\n';
                continue;
            }
            auto it = mp.upper_bound(y);
            if(it != mp.end()){
                ans += (*it).fi * (*it).se;
            }
            if(mp.count(y)){
                ans += mp[y] * y;
                if((*mp.begin()).fi != y){
                    it = prev(prev(it));
                    ans += (*it).fi * (*it).se;
                }
            }
            else if(mp.begin() != it){
                it = prev(it);
                ans += (*it).fi * (*it).se;
            }
            cout << ans << '\n';
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