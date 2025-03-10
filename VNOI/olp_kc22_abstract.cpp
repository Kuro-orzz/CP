// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<int>> see(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        int t = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j] > t){
                t = a[i][j];
                see[i][j] = 1;
            }
        }
        t = 0;
        for(int j = m-1; j >= 0; j--)
            if(a[i][j] > t){
                t = a[i][j];
                see[i][j] = 1;
            }
    }
    for(int j = 0; j < m; j++){
        int t = 0;
        for(int i = 0; i < n; i++)
            if(a[i][j] > t){
                t = a[i][j];
                see[i][j] = 1;
            }
        t = 0;
        for(int i = n-1; i >= 0; i--)
            if(a[i][j] > t){
                t = a[i][j];
                see[i][j] = 1;
            }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(see[i][j])
                ans++;
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
