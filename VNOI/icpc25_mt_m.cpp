/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

int n;
vector<pii> a, t;
pii A, B;
vector<int> used;
int ans = 1e9;

int dist(pii a, pii b) { return abs(a.fi - b.fi) + abs(a.se - b.se); }

void calc() {
    for (int i = 0; i < n; i++) {
        int fuelA = 0;
        for (int j = 1; j < i; j++) {
            fuelA += dist(t[j-1], t[j]) * j;
        }
        if (i) fuelA += dist(t[i-1], A) * i;
        int fuelB = 0;
        for (int j = i+1; j < n; j++) {
            fuelB += dist(t[j-1], t[j]) * (j - i);
        }
        fuelB += dist(t[n-1], B) * (n - i);
        ans = min(ans, fuelA + fuelB);
    }
}

void backtrack(int cur, int idx) {
    if (cur == n) {
        calc();
        return;
    }
    used[idx] = 1;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        t.push_back(a[i]);
        backtrack(cur + 1, i);
        t.pop_back();
    }
    used[idx] = 0;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
    cin >> A.fi >> A.se;
    cin >> B.fi >> B.se;
    used.resize(n);
    for (int i = 0; i < n; i++) {
        used[i] = 1;
        t.push_back(a[i]);
        backtrack(1, i);
        t.pop_back();
        used[i] = 0;
    }
    cout << ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}