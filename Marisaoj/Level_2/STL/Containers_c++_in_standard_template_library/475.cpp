#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1506;
int q;
multiset<int> s;

void solve(){
    cin >> q;
    while(q--){
        int type, x; cin >> type >> x;
        if(type == 1)
            s.insert(x);
        else if(type == 2){
            auto it = s.find(x);
            if(it != s.end())
                s.erase(it);
        }
        else if(type == 3){
            auto it = s.upper_bound(x);
            if(it != s.end())
                cout << *it << '\n';
            else cout << -1 << '\n';
        }
        else{
            auto it = s.upper_bound(x);
            if(it != s.begin())
                cout << *prev(it) << '\n';
            else cout << -1 << '\n';
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