#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

class SegTreeBeats {
public:
	struct Node {
		ll Max, sum;

		Node() {}

		Node(int val) {
			Max = val;
			sum = val;
		}

		Node operator+(const Node &b) {
			Node res;
			res.Max = max(Max, b.Max);
			res.sum = sum + b.sum;
			return res;
		}
	};

	vector<Node> tree;

	SegTreeBeats(int n): tree(4*n) {}

	void build(int id, int l, int r, int u, int v, int val) {
		if (l > v || r < u) return;
		if (u <= l && r <= v) {
			tree[id] = Node(val);
			return;
		}
		int mid = (l + r) >> 1;
		build(id*2, l, mid, u, v, val);
		build(id*2+1, mid+1, r, u, v, val);
		tree[id] = tree[id*2] + tree[id*2+1];
	}	

	void updateMod(int id, int l, int r, int u, int v, int x) {
		if (l > v || r < u) return;
		if (tree[id].Max < x) return;
		if (l == r) {
			tree[id].Max %= x;
			tree[id].sum = tree[id].Max;
			return;
		}
		int mid = (l + r) >> 1;
		updateMod(id*2, l, mid, u, v, x);
		updateMod(id*2+1, mid+1, r, u, v, x);
		tree[id] = tree[id*2] + tree[id*2+1];
	}

	ll getSum(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return 0;
		if (u <= l && r <= v) return tree[id].sum;
		int mid = (l + r) >> 1;
		ll t1 = getSum(id*2, l, mid, u, v);
		ll t2 = getSum(id*2+1, mid+1, r, u, v);
		return t1 + t2;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	SegTreeBeats st(n);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		st.build(1, 1, n, i, i, x);
	}
	while (m--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r; cin >> l >> r;
			cout << st.getSum(1, 1, n, l, r) << '\n';
		} else if (type == 2) {
			int l, r, x; cin >> l >> r >> x;
			st.updateMod(1, 1, n, l, r, x);
		} else if (type == 3) {
			int k, x; cin >> k >> x;
			st.build(1, 1, n, k, k, x);
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}