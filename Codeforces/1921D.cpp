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
    int n, m; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int b[m];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+m, greater<int>());
    int b_cnt1 = 0;
    int b_cnt2 = m-1;
    int a_cnt1 = 0;
    int a_cnt2 = n-1;
    ll ans = 0;
    while(a_cnt1 <= a_cnt2){
        if(abs(a[a_cnt1]-b[b_cnt1]) > abs(a[a_cnt2]-b[b_cnt2])){
            ans += abs(a[a_cnt1]-b[b_cnt1]);
            a_cnt1++;
            b_cnt1++;
        }
        else{
            ans += abs(a[a_cnt2]-b[b_cnt2]);
            a_cnt2--;
            b_cnt2--;
        }
    }
    cout << ans << '\n';
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
