// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("XOAPT.inp", "r", stdin);
#define fileout() freopen("XOAPT.out", "w", stdout);
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
    int n; cin >> n;
    vi v(n);
    int le = 0;
    int chan = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
        if(v[i]%2==0)
            chan++;
        else
            le++;
    }
    if(sum%2==0)
        cout << chan;
    else
        cout << le;
}

int main(){
    fast();
    filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
     cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
