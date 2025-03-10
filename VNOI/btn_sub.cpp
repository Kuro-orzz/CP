// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("sub.inp", "r", stdin);
#define fileout() freopen("sub.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 10000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    int n, s; cin >> n >> s;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int ans = n;
    int sum = 0;
    int pos = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(sum >= s){
            while(pos < i && sum-v[pos] >= s){
                sum -= v[pos];
                pos++;
            }
        }
        ans = ((sum >= s) ? min(ans, i-pos+1) : ans);
    }
    cout << ans;
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
