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

template <typename T>
class Hash {
public:
    static constexpr int base = 331;
    static constexpr int mod = 1'000'000'007;
    vector<T> h, p;

    Hash() {}

    Hash(const string &s) {
        build(s);
    }

    void build(const string &s) {
        int n = s.size();
        h = hashStr(s, n);
        p = calc_pow(n);
    }

    T getHash(int l, int r) const {
        T x = (h[r] - 1ll * h[l-1] * p[r-l+1]) % mod;
        return T((x + mod) % mod);
    }

private:
    vector<T> hashStr(const string &s, int n) {
        vector<T> hash(n + 1);
        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a' + 1;
            hash[i] = (1ll * hash[i-1] * base + c) % mod;
        }
        return hash;
    }

    vector<T> calc_pow(int n) {
        vector<T> P;
        P.emplace_back(1);
        for (int i = 1; i <= n; i++) {
            P.emplace_back((1ll * P[i-1] * base) % mod);
        }
        return P;
    }
};
 
void solve(){
    string s; cin >> s;
    int n = s.size();
    Hash<int> h(s);
    for (int i = 1; i <= n; i++) {
        int val = h.getHash(1, i);
        bool check = true;
        for (int j = i+1; j <= n; j += i) {
            if (j+i-1 > n) {
                if (h.getHash(j, n) != h.getHash(1, n-j+1)) {
                    check = false;
                    break;
                }
            } else if (h.getHash(j, j+i-1) != val) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << s.substr(0, i);
            return;
        }
    }
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