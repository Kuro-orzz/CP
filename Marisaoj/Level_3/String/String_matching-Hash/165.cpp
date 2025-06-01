#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

class KMP {
public:
    size_t n, m;
    string S, T;
    vector<int> pi;

    KMP() {}

    KMP(string s1, string s2): S(s1), T(s2) {
        n = s1.size();
        m = s2.size();
    }

    void LPS() {
        pi.resize(n);
        for (size_t i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && S[i] != S[j]) {
                j = pi[j - 1];
            }
            if (S[i] == S[j]) j++;
            pi[i] = j;
        }
    }

    vector<int> __KMP() {
        if (n == 0) return {};
        LPS();
        int j = 0;
        vector<int> ans(m);
        for (size_t i = 0; i < m; i++) {
            while (j > 0 && T[i] != S[j]) {
                j = pi[j - 1];
            }
            if (T[i] == S[j]) j++;
            ans[i] = j;
            if (j == n) {
                j = pi[j - 1];
            }
        }
        return ans;
    }
};

void solve() {
    string s1, s2; cin >> s1 >> s2;
    KMP kmp(s2, s1);
    vector<int> ans = kmp.__KMP();
    int res = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (ans[i] == s2.size()) res++;
    }
    cout << res;
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
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