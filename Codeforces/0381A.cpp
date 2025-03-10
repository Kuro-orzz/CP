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
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int cnt1 = 0;
    int cnt2 = n-1;
    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(a[cnt1] > a[cnt2]){
                ans1 += a[cnt1];
                cnt1++; 
            }
            else{
                ans1 += a[cnt2];
                cnt2--;
            }
        }
        else{
            if(a[cnt1] > a[cnt2]){
                ans2 += a[cnt1];
                cnt1++; 
            }
            else{
                ans2 += a[cnt2];
                cnt2--;
            }
        }
    }
    cout << ans1 << " " << ans2;
}

int main(){
    fast(); //cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
