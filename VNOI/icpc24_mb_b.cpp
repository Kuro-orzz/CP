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

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> dog(n, vector<int>(3));
    // weight, intelligence, value
    for (int i = 0; i < n; i++) {
        cin >> dog[i][0] >> dog[i][1] >> dog[i][2];
    }
    sort(all(dog), cmp);
    vector<ll> dp;
    for (int i = 0; i < n; i++) {
        dp.push_back(dog[i][2]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (dog[i][1] <= dog[j][1]) {
                dp[j] = max(dp[j], dp[i] + dog[j][2]);
            }
        }
    }
    cout << *max_element(all(dp));
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