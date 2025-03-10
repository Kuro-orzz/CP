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
    ll a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll near[n];
    near[0] = 0;
    near[1] = 1;
    for(int i = 2; i < n; i++)
        if(a[i]-a[i-1] < a[i-1]-a[i-2])
            near[i] = near[i-1] + 1;
        else
            near[i] = near[i-1] + a[i]-a[i-1];
    ll nguoc[n];
    nguoc[n-1] = 0;
    nguoc[n-2] = 1;
    for(int i = n-3; i >= 0; i--){
        if(a[i+1]-a[i] < a[i+2]-a[i+1])
            nguoc[i] = nguoc[i+1] + 1;
        else
            nguoc[i] = nguoc[i+1] + a[i+1]-a[i];
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        if(x < y)
            cout << abs(near[y-1]-near[x-1]) << '\n';
        else
            cout << abs(nguoc[x-1]-nguoc[y-1]) << '\n';
    }
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
