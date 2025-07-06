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

int a[1000];

// negative
bool cmp1(int x, int y) { return a[x] > a[y]; }
// positive
bool cmp2(int x, int y) { return a[x] < a[y]; }

void solve() {
    int n; cin >> n;
    vector<int> pos, neg, zero;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) pos.push_back(i);
        else if (a[i] < 0) neg.push_back(i);
        else zero.push_back(i);
    }
    sort(all(neg), cmp1);
    sort(all(pos), cmp2);
    int remove = -1;
    if ((int)neg.size() % 2) {
        remove = neg[0];
    } else if (zero.size() > 0) {
        remove = zero[0];
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (i == remove) continue;
        ans = ans * a[i] % MOD;
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