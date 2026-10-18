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

void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n), C(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];
    sort(all(A));
    sort(all(B));
    sort(all(C));
    int p1 = 0, p2 = 0, p3 = 0;
    ll ans = LLONG_MAX;
    while (p1 < n && p2 < n && p3 < n) {
        ans = min(ans, 1ll * (abs(A[p1]-B[p2]) + abs(B[p2]-C[p3]) + abs(C[p3]-A[p1])));
        if (A[p1] <= B[p2] && A[p1] <= C[p3]) {
            p1++;
        } else if (B[p2] <= A[p1] && B[p2] <= C[p3]) {
            p2++;
        } else {
            p3++;
        }
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