#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

vector<int> primeFactor(ll n) {
    vector<int> factor;
    for (int i : {2, 3, 5}) {
        while (n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
    }
    int inc[] = {4, 2, 4, 2, 4, 6, 2, 6};
    int j = 0;
    for (ll i = 7; i * i <= n; i += inc[j%8], j++) {
        while(n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
    }
    if (n > 1) factor.push_back(n);
    return factor;
}

ll binPow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}

void solve() {
    ll n, m; cin >> n >> m;
    if (n == m) {
        cout << "0\n";
        return;
    }
    if (n > m || m % n != 0 || n == 1) {
        cout << "-1\n";
        return;
    }
    int x = m/n;
    vector<int> factorN = primeFactor(n);
    vector<int> factorX = primeFactor(x);
    unordered_map<int, int> mp1, mp2;
    for (int x : factorN) mp1[x]++;
    for (int x : factorX) mp2[x]++;
    for (auto it : mp2) {
        if (!mp1.count(it.fi)) {
            cout << "-1\n";
            return;
        }
    }
    int ans = 0;
    vector<int> res;
    while (n < m) {
        int mul = 1;
        for (auto &it : mp2) {
            int cnt = 0, tmp = n;
            while (tmp % it.fi == 0) {
                tmp /= it.fi;
                cnt++;
            }
            int mn = min(it.se, cnt);
            mul *= binPow(it.fi, mn);
            it.se -= mn;
        }
        n *= mul;
        ans++;
        res.push_back(mul);
    }
    cout << ans << " ";
    for (int x : res) cout << x << " ";
    cout << '\n';
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
