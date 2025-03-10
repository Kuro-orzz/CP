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
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    set<int> s;
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    ll ans = 0; 
    for (int i = 1; i < n - 1; ++i) { 
        int max1 = 0;
        int max2 = 0; 
        for (int j = 0; j < i; ++j) 
            if (v[j] < v[i]) 
                max1 = max(max1, v[j]); 

        for (int j = i + 1; j < n; ++j) 
            if (v[j] > v[i]) 
                max2 = max(max2, v[j]); 
  
        if(max1 && max2) 
            ans = max(ans, 1ll*max1+v[i]+max2); 
    }
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
