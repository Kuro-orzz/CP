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
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    int pos = 1;
    while(pos < n && a[pos-1] >= a[pos])
        pos++;
    int val1 = a[pos-1];
    int val2 = a[pos];
    for(int i = pos+1; i < n; i++){
        if(a[i] <= val1 && a[i] <= val2){
            if(val1 <= val2)
                val1 = a[i];
            else
                val2 = a[i];
        }
        else if(a[i] <= val1){
            val1 = a[i];
        }
        else if(a[i] <= val2){
            val2 = a[i];
        }
        else{
            if(val1 <= val2){
                val1 = a[i];
                ans++;
            }
            else if(val1 > val2){
                val2 = a[i];
                ans++;
            }
        }
        pos++;
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