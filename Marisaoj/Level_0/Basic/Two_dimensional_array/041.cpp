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
    int n, m, q; cin >> n >> m >> q;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    while(q--){
        int tv, i, j; cin >> tv >> i >> j;
        i--; j--;
        if(tv == 1){
            for(int k = 0; k < m; k++)
                swap(a[i][k], a[j][k]);
        }
        else{
            for(int k = 0; k < n; k++)
                swap(a[k][i], a[k][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
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