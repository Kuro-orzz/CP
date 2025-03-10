// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 1000006
#define tuple64 tuple<ll, int, int>

void solve(){ 
    int n; cin >> n;
    vector<vi> v(n, vi(3));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> v[i][j];
    vector<vi> dp(n, vi(3, 0));
    int prev;
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                if(j != k)
                    dp[i][j] = max(dp[i][j], dp[i-1][k]+v[i][j]);
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
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
