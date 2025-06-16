#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

pii CanWin(string &s) {
    int cntU = 0, cntI = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i-1]) {
            if (i-2 >= 0 && s[i-2] != s[i]) {
                return {i-1, i+1};
            } else if (i+1 < s.size() && s[i+1] != s[i]) {
                return {i, i+2};
            }
        } else {
            if (i-2 >= 0) return {i-1, i+1};
            else if (i+1 < s.size()) return {i, i+2};
        }
    }
    return {-1, -1};
}

void solve() {
    string s; cin >> s;
    int cntU = 0, cntI = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'U') cntU++;
        else cntI++;
    }
    if (cntU == 0 || cntI == 0 || s.size() < 3) {
        cout << "NO\n";
        return;
    }
    pii ans = CanWin(s);
    if (ans == make_pair(-1, -1)) {
        cout << "NO\n";
    } else {
        cout << "YES " << ans.fi << " " << ans.se << '\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
