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
vector<int> a;

void solve(){
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        int d = upper_bound(all(a), a[i]+n-1)-lower_bound(all(a), a[i]);
        ans = max(ans, d);
    }
    cout << n-ans;
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