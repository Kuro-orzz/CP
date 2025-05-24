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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<vi> a(n, vi(m)), b(x, vi(y));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            cin >> b[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == b[0][0] && i+x-1 < n && j+y-1 < m){
                bool ch = true;
                for(int k = 0; k < x; k++)
                    for(int t = 0; t < y; t++){
                        if(a[i+k][j+t] != b[k][t])
                            ch = false;
                    }
                if(ch){
                    cout << "YES";
                    return;
                }
            }
        }
    cout << "NO";
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