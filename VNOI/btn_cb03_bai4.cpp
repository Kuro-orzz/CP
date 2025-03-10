// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("TROCHOI.inp", "r", stdin);
#define fileout() freopen("TROCHOI.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 1000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second
int a[1000000];
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ll ans = 0;
    ll sum = 0;
    int cnt = 1;
    bool check = false;
    while(m--){
        int x; cin >> x;
        if(binary_search(a, a+n, x)){
            sum += cnt;
            cnt++;
        }
        else{
            cnt = 1;
            sum = 0;
        }
        ans = max(ans, sum);
    }
    cout << ans;
}

int main(){
    fast();
    filein(); fileout();    
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}