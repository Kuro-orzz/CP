#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    string s; cin >> s;
    bool ch_zero = false;
    ll sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += s[i]-'0';
        if(s[i] == '0')
            ch_zero = true;
    }
    if(sum % 3 != 0 || !ch_zero)
        cout << -1;
    else{
        sort(all(s), greater<int>());
        cout << s;
    }
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
