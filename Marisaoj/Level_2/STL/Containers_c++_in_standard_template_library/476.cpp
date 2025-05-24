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
set<pair<ll, int>> cnt;
 
void del(int val, ll fre){
    if(cnt.count({fre, val}))
        cnt.erase({fre, val});
}
 
void ins(int val, ll fre){
    cnt.insert({fre, val});
}
 
void solve(){
    cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x, a; cin >> x >> a;
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
            auto it = cnt.rbegin()->se;
            cout << it << '\n';
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