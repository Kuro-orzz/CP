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

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define INF 2147483647
#define bit(s, i) (s&(1<<i))
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve(){
    int n; cin >> n;
    vi a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        tmp = INF^a[i];
        if(mp[a[i]] == 0){
            ans++;
            mp[tmp]++;
        }
        else
            mp[a[i]]--;
    }
    cout << ans << '\n';
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}