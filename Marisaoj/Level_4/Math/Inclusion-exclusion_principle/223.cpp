#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5+6;
ll n, l, r, ans = 0;
vector<int> a;
set<int> s;

void solve(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);        
    }
    for(int x : s) a.push_back(x);
    n = a.size();
    for(int i = 1; i < (1 << n); i++){
        ll mul = 1, bit = 0;
        bool check = true;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1){
                if(1e18 / a[j] < mul){
                    check = false;
                    break;
                }
                mul *= a[j];
                bit++;
            }
        }
        if(!check) continue;
        ll t = r/mul - (l-1)/mul;
        if(bit % 2) ans += bit*t;
        else ans -= bit*t;
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