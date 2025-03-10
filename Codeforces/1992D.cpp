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
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    s = 'L'+s+'L';
    n+=2;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            for(int j = 1; j <= m; j++){
                if(i+j >= n) break;
                if(s[i+j] == 'L')
                    dp[i+j] = min(dp[i+j], dp[i]);
                else if(s[i+j] == 'W')
                    dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        else if(s[i] == 'W'){
            if(s[i+1] == 'L')
                dp[i+1] = min(dp[i+1], dp[i]);
            else if(s[i+1] == 'W')
                dp[i+1] = min(dp[i+1], dp[i]+1);
        }
    }
    // for(int x : dp)
    //     cout << x << " ";
    if(dp[n-1] <= k) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}