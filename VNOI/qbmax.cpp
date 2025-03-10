// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N (int)1e7
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 506

void solve(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int dp[n][m];
    for(int i = 0; i < n; i++)
        dp[i][0] = a[i][0];
    
    for(int j = 1; j < m; j++){
        for(int i = 0; i < n; i++){
            dp[i][j] = INT_MIN;
            for(int t = -1; t <= 1; t++)
                if(i+t >= 0 && i+t < n)
                    dp[i][j] = max(dp[i][j], a[i][j]+dp[i+t][j-1]);
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i][m-1]);
    cout << ans;
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
