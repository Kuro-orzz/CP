#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int a[501][501];
ll pre[501][501];

void prefix_2d(int n, int m){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!i || !j) pre[i][j] = 0;
            else pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i-1][j-1];
        }
    }
}

ll kadane(int n, int m){
    ll ans = -1e9;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++){
            vector<ll> preCol(m+1, 0);
            for(int k = 1; k <= m; k++)
                preCol[k] = pre[j][k]-pre[j][k-1]-pre[i-1][k]+pre[i-1][k-1];
            ll sum = 0;
            for(int k = 1; k <= m; k++){
                sum += preCol[k];
                ans = max(ans, sum);
                sum = max(sum, 1ll*0);
            }
        }
    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    prefix_2d(n, m);
    cout << kadane(n, m);
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