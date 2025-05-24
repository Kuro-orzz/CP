#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e3+6;
int n, m, q;
ll a[maxn][maxn];

void solve(){
    cin >> n >> m >> q;
    while (q--) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++; a[x2+1][y2+1]++;
        a[x1][y2+1]--; a[x2+1][y1]--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
            cout << a[i][j] << ' ';
        }
        cout << endl;
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