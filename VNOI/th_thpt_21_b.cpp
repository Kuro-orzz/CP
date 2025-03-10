// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("BAI2.INP", "r", stdin);
#define fileout() freopen("BAI2.OUT", "w", stdout);
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
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    stringstream ss1(s1), ss2(s2);
    string tmp1, tmp2;
    int ans = 0;
    while(ss1 >> tmp1 && ss2 >> tmp2){
        int cnt = 0;
        bool check = true;
        for(int i = 0; i < tmp1.length(); i++)
            if(tmp1[i] == tmp2[cnt])
                cnt++;
            else if(tmp1[i] != tmp1[i-1]){
                check = false;
                break;
            }
        if(check)
            ans++;
    }
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
