#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1006;
int n, k;
int a[maxn][maxn];
ll r[3*maxn][3*maxn], pre[3*maxn][3*maxn];

void init_2d_prefix(int n){
    for(int i = 1; i < 3*maxn; i++)
        for(int j = 1; j < 3*maxn; j++)
            pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+r[i][j];
    // for(int i = 1; i <= 2*n; i++){
    //     for(int j = 1; j <= 2*n; j++)
    //         cout << r[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << endl;
}

ll manhattan_dist(int x, int y){
    int x1 = max(x-k-1, 0), y1 = max(y-k-1, 0);
    int x2 = min(x+k, 2*maxn-1), y2 = min(y+k, 2*maxn-1);
    return pre[x2][y2]-pre[x1][y+k]-pre[x+k][y1]+pre[x1][y1];
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            int x = i+j, y = i-j+n+1;
            r[x][y] = a[i][j];
        }
    init_2d_prefix(n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x = i+j, y = i-j+n+1;
            cout << manhattan_dist(x, y) << " ";
        }
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