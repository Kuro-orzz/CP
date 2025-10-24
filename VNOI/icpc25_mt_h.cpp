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

int n, T, k;
vector<int> a, used;
vector<vector<int>> ans;

bool isValid(vector<int> &a) {
    int sum = 0;
    for (int i = 0; i < k; i++) sum += a[i];
    if (sum != T) return false;
    sum = 0;
    for (int i = k-1; i < 2*k-1; i++) sum += a[i];
    if (sum != T) return false;
    sum = a[0];
    for (int i = 2*k-2; i < n; i++) sum += a[i];
    return sum == T;
}

void backtrack(vector<int> &a, int i) {
    if (i == n) {
        if (isValid(a)) ans.push_back(a);
        return;
    }
    if (i == k) {
        int sum = 0;
        for (int i = 0; i < k; i++) sum += a[i];
        if (sum != T) return;
    } else if (i == 2 * k - 1) {
        int sum = 0;
        for (int i = k-1; i < 2*k-1; i++) sum += a[i];
        if (sum != T) return;
    }
    for (int j = 1; j <= n; j++) {
        if (used[j]) continue;
        used[j] = 1;
        a.push_back(j);
        backtrack(a, i+1);
        used[j] = 0;
        a.pop_back();
    }
}

void solve() {
    cin >> n >> T;
    k = n / 3 + 1;
    used.resize(n+1);
    backtrack(a, 0);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    if (ans.empty()) cout << -1;
    else cout << ans.size();
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