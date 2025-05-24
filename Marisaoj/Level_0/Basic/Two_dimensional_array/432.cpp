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
    int n; cin >> n;
    vector<vi> a(n, vi(n)), ans(n, vi(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            ans[j][n-i-1] = a[i][j];
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
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