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
int n, x;
vector<int> a, b;
map<int, int> mp[2];

void solve(){
    cin >> n >> x;
    a.resize(n+1);
    b.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[0][a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        mp[1][b[i]]++;
    }
    ll ans = 0;
    for(auto it : mp[0]){
        ans += it.se * mp[1][x-it.fi];
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