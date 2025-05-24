#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

struct Block {
    vector<int> v;
    int sz = 0, assigned = -1;
    bool rev = false;
    ll sum = 0;

    Block() {}
    
    Block(int _sz, int _assign, bool _rev = false) {
        this->sz = _sz;
        this->assigned = _assign;
        this->rev = _rev;
    }

    Block(vector<int> &a, int _assign = -1, bool _rev = false) {
        this->v = a;
        this->sz = a.size();
        this->assigned = _assign;
        this->rev = _rev;
        this->sum = accumulate(all(a), 0LL);
    }

    int size() { return sz; }

    ll getSum() { return assigned != -1 ? 1LL * assigned * sz : sum; }

    void perform_reverse() {
        rev ^= true;
        if (assigned != -1) return;
        reverse(all(v));
    }

    void truncate(int k) {
        sz = k;
        if (rev) perform_reverse();
        if (assigned != -1) return;
        v.resize(k);
        if (assigned != -1) {
            sum = 1LL * assigned * sz;
        } else {
            sum = accumulate(all(v), 0ll);
        }
    }
};

struct Sqrt {
    int n, cnt, block_sz = 450;
    vector<Block> blocks;
    vector<int> a, blockId;

    Sqrt() {}
    Sqrt(int _n, vector<int> &a) {
        this->n = _n;
        this->a = a;
        cnt = 0;
        blocks.assign(4000, {});
    }

    void rebuild() {
        cnt = 0;
        blockId.clear();
        for (int i = 1; i <= n; i += block_sz) {
            int l = i, r = min(i + block_sz - 1, n);
            vector<int> v(a.begin() + l, a.begin() + r + 1);
            blocks[++cnt] = Block(v);
            blockId.push_back(cnt);
        }
    }

    int split(int i) {
        if (i > n) return blockId.size();
        int curPos = 1;
        for (auto it = blockId.begin(); it != blockId.end(); it++) {
            int id = *it;
            int curL = curPos, curR = curPos + blocks[id].size() - 1;
            if (curL <= i && i <= curR) {
                if (i == curL) return it-blockId.begin();
                
                if (blocks[id].rev) {
                    blocks[id].perform_reverse();
                }
                int k = i - curL;
                int newId = ++cnt;
                if (blocks[id].assigned != -1) {
                    blocks[newId] = Block(curR - curL + 1 - k, blocks[id].assigned);
                } else {
                    vector<int> tail = vector<int>(blocks[id].v.begin() + k, blocks[id].v.end());
                    blocks[newId] = Block(tail);
                }
                blocks[id].truncate(k);
                ++it;
                it = blockId.insert(it, newId);
                return it - blockId.begin();
            }
            curPos = curR + 1;
        }
        return 0;
    }

    ll sum(int l, int r) {
        l = split(l), r = split(r + 1);
        ll res = 0;
        for (int j = l; j < r; ++j)
            res += blocks[ blockId[j] ].getSum();
        return res;
    }

    void Reverse(int l, int r) {
        l = split(l), r = split(r + 1);
        for (int j = l; j < r; ++j)
            blocks[blockId[j]].rev ^= 1;
        reverse(blockId.begin() + l, blockId.begin() + r);
    }

    void rebuild_if_need() {
        a.resize(1);
        for (auto it : blockId) {
            if (blocks[it].rev) {
                blocks[it].perform_reverse();
            }
            if (blocks[it].assigned == -1) {
                for (auto x : blocks[it].v)
                    a.push_back(x);
            } else {
                for (int i = 0; i < blocks[it].sz; i++)
                    a.push_back(blocks[it].assigned);
            }
        }
        n = a.size() - 1;
        rebuild();
    }
};

void solve() {    
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Sqrt sqrt(n, a);
    sqrt.rebuild();
    while (q--) {
        if (sqrt.blockId.size() > 3000) sqrt.rebuild_if_need();
        int type, l, r; cin >> type >> l >> r;
        if (type == 1) {
            sqrt.Reverse(l, r);
        } else if (type == 2) {
            cout << sqrt.sum(l, r) << '\n';
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
