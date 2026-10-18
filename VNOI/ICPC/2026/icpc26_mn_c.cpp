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
Ta có thể dễ dàng nhận ra rằng:
- Nếu pivot ở giữa mảng, số lượng thao tác và đệ quy sẽ < n
- Nếu pivot là max hoặc min của mảng thì mỗi lần length sẽ chỉ giảm 1 và đệ quy n lần -> tot_length sẽ max

Ta có thể tính được pivot_index của từng lần đệ quy: (khi chọn pivot là max)
- pivot_index = 1 + (R[i] % (n-i+1))
- Sau đó gán giá trị max vào vị trí đó (vị trí của mảng gốc a[])
- Sau đó remove giá trị ở vị trí đó khỏi mảng

Để thuận tiện cho việc remove và search:
- Update: fenwick tree O(1)
- Search: binary search log(n)
*/
template <typename T>
struct Fenwick{
    int n;
    vector<T> fen;

    Fenwick() {}
    Fenwick(int _n): n(_n), fen(_n+1) {}

    void update(int pos, T val) {
        for (; pos <= n; pos += pos & -pos) {
            fen[pos] += val;
        }
    }

    T get(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= pos & -pos) {
            ans += fen[pos];
        }
        return ans;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    void update_range(int l, int r, T val){
        update(l, val);
        update(r+1, -val);
    }

    void reset() {
        fill(all(fen), T(0));
    }
};

void solve() {
    int n; cin >> n;
    vector<int> r(n+1);
    for (int i = 1; i <= n; i++) cin >> r[i];

    Fenwick<int> BIT(n+1);
    for (int i = 1; i <= n; i++) {
        BIT.update(i, 1);
    }
    vector<int> a(n+1, 0);
    int cur_mx = n;
    for (int i = 1; i <= n; i++) {
        int idx = 1 + (r[i] % (n-i+1));
        int l = 1, r = n, res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (BIT.get(mid) > idx) r = mid - 1;
            else if (BIT.get(mid) < idx) l = mid + 1;
            else {
                res = mid;
                r = mid - 1;
            }
        }
        a[res] = cur_mx--;
        BIT.update(res, -1);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
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
