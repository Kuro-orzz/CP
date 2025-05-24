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
int n, k, a[maxn];
map<int, int> mp;

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++) {
        mp[a[r]]++;
        while (mp.rbegin()->fi-mp.begin()->fi > k) {
            mp[a[l]]--;
            if(mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        ans += r-l+1;
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