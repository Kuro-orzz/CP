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
    string ans = "";
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(i && s[i] != s[i-1]){
            ans += to_string(cnt);
            ans += s[i-1]; 
            cnt = 1;
        }
        else cnt++;
    }
    ans += to_string(cnt)+s[s.size()-1];
    cout << ans << '\n';
    string x; cin >> x;
    for(int i = 0; i < x.size();){
        string t = "";
        while(isdigit(x[i])){
            t += x[i];
            i++;
        }
        for(int j = 0; j < stoi(t); j++)
            cout << x[i];
        i++;
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