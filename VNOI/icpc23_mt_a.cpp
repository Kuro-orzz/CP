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

template <typename T>
struct SegTree {
    int n;
    vector<T> tree;

    SegTree() {}
    SegTree(int _n): n(_n), tree(_n*4) {}

    void update(int pos, T val) {
        update(1, 1, n, pos, val);
    }

    T getMax(int u, int v) {
        return getMax(1, 1, n, u, v);
    }

    void update(int id, int l, int r, int pos, T val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            tree[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id*2, l, mid, pos, val);
        update(id*2+1, mid+1, r, pos, val);
        tree[id] = max(tree[id*2], tree[id*2+1]);
    }

    T getMax(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return tree[id];
        int mid = (l + r) >> 1;
        T t1 = getMax(id*2, l, mid, u, v);
        T t2 = getMax(id*2+1, mid+1, r, u, v);
        return max(t1, t2);
    }
};

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    int ans = INT_MIN, sum = 0;
    SegTree<int> st(n);
    for (int i = 0; i < n; i++) {
        st.update(i+1, a[i]);
    }
    for (int r = 0; r < n; r++) {
        sum += a[r];
        int mxRange = st.getMax(l+1, r+1);
        if (sum < 0) {
            sum = 0;
            l = r+1;
        }
        ans = max(ans, sum - mxRange);
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