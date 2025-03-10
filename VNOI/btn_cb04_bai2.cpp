// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("BIEUTHUC.inp", "r", stdin);
#define fileout() freopen("BIEUTHUC.out", "w", stdout);
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
    int a[3];
    for(int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a+3);
    ll ans = a[2];
    for(int i = 0; i < 2; i++)
        if(a[i] >= 0)
            ans += a[i];
        else
            ans -= a[i];
    cout << ans;
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
