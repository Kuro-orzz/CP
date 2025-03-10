#define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("CAU4.INP", "r", stdin);
#define fileout() freopen("CAU4.OUT", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N 1000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

void solve(){
    string s; cin >> s;
    vi v1;
    vi v2;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u')
            v1.pb(i);
        else
            v2.pb(i);
    }
    ll ans = 0;
    for(int i = 0; i < v1.size(); i++)
        ans += s.length()-v1[i]-v1.size()+i;
    for(int i = 0; i < v2.size(); i++)
        ans += s.length()-v2[i]-v2.size()+i;
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
