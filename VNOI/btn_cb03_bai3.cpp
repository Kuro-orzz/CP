// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("PRIZE.inp", "r", stdin);
#define fileout() freopen("PRIZE.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 10000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fi first
#define se second

map<char, int> mp;
bool check(string s){
    map<char, int> m;
    for(int i = 0; i < s.length(); i++)
        m[s[i]]++;
    for(auto it : mp)
        if(it.se > m[it.fi])
            return false;
    return true;
}

void solve(){
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++)
        mp[s[i]]++;
    int ans = 0;
    int t; cin >> t;
    while(t--){
        string x; cin >> x;
        if(check(x))
            ans++;
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
