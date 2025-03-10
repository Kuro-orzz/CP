// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("BANNHA.inp", "r", stdin);
#define fileout() freopen("BANNHA.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 100000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    int n; cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    unordered_map<int, int> mp;
    int ans = 0;
    int cnt = 0;
    pii res = {1, 1};
    for(int i = 1; i <= n; i++){
        if(mp[a[i]] == 0){
            cnt++;
            mp[a[i]] = i;
        }
        else{
            for(int j = i-cnt; j < mp[a[i]]; j++)
                mp[a[j]] = 0; 
            cnt = i-mp[a[i]];
            mp[a[i]] = i;
        }
        if(res.se-res.fi+1 < cnt){
            res.fi = i-cnt+1;
            res.se = i;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    cout << res.fi << " " << res.se;
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    // cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
