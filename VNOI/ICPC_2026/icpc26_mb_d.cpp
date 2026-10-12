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

/*
Xét số bit 1 của a[i]:
- Nếu >= 1: dễ thấy 2^a + 2^b >= 2^(a+1) -> chọn xẻng a+1 tối ưu nhất
- Nếu = 1: chọn xẻng ở vị trí của bit 1 sẽ tối ưu nhất
*/
int sol_type_1(int n, vector<ll> a, int x) {
    int left = 0, right = 0;
    for (int i = x-1; i >= 0; i--) {
        int x = __lg(a[i]);
        left += x + 1 + (1ll << x != a[i]);
        if (i) a[i-1] += a[i];
    }
    for (int i = x; i < n; i++) {
        int x = __lg(a[i]);
        right += x + 1 + (1ll << x != a[i]);
        if (i != n-1) a[i+1] += a[i];
    }
    return left + right;
}

/*
Chọn vị trí x bất kì, với mỗi bên trái và phải ta sẽ có dải giá trị từ 1 -> 40 (0 <= k <= 39)
- Idea: sử dụng prefix và suffix sum, sau đó binary search để xem mỗi bên có bao nhiêu tiles nằm trong khoảng giá trị 1,2,3,..,40
- Complexity: O(40nlog(n))
*/
int sol_type_2(int n, vector<ll> a) {
    vector<ll> pref(n+1, 0), suff(n+1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i-1];
    for (int i = n-1; i >= 0; i--) suff[i] = suff[i+1] + a[i];
    reverse(all(suff));

    int ans = -1, mn_val = INT_MAX;
    for (int x = 1; x < n; x++) {
        int cur_left = n - x + 1, cur_right = x + 1;
        ll base_left = suff[n-x], base_right = pref[x];
        vector<int> shovel(40, 0);

        // khoảng giá trị cần 1 xẻng k (1 << (k-1), 1 << k]
        for (int k = 0; k < 40; k++) {
            // left
            if (cur_left < n + 1) {
                auto it = upper_bound(suff.begin()+cur_left, suff.end(), base_left + (1ll << k)) - suff.begin();
                shovel[k] += it - cur_left;
                cur_left = it;
            }
            // right
            if (cur_right < n + 1) {
                auto it = upper_bound(pref.begin()+cur_right, pref.end(), base_right + (1ll << k)) - pref.begin();
                shovel[k] += it - cur_right;
                cur_right = it;
            }
        }
        int total_energy = 0;
        for (int k = 0; k < 40; k++) total_energy += shovel[k] * (k + 1);
        if (total_energy < mn_val) {
            mn_val = total_energy;
            ans = x;
        }
    }
    return ans;
}

void solve() {
    int type; cin >> type;
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (type == 1) {
        int x; cin >> x;
        cout << sol_type_1(n, a, x);
    } else {
        cout << sol_type_2(n, a);
    }
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