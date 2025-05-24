#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool check(string &s, int l, int r){
    for(int i = l; i <= (r+l)/2; i++)
        if(s[i] != s[r-i+l])
            return false;
    return true;
}

void solve(){
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        for(int j = i; j < s.size(); j++)
            if(s[i] == s[j]){
                if(check(s, i, j)) ans++;
            }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}