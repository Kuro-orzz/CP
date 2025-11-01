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

struct Node {
    int child[26], isEnd;

    Node() {
        memset(child, 0, sizeof child);
        isEnd = 0;
    }
};

class Trie {
public:
    int n, curVertex;
    vector<Node> tree;

    Trie() {}
    Trie(int _n): n(_n+1), curVertex(0) {
        tree.assign(n+1, Node());
    }

    void add(const string &s) {
        int u = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            if (!tree[u].child[k]) {
                tree[u].child[k] = ++curVertex;
            }
            u = tree[u].child[k];
        }
        tree[u].isEnd++;
    }

    bool search(const string &s) {
        int u = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            if (!tree[u].child[k]) {
                return 0;
            }
            u = tree[u].child[k];
        }
        return tree[u].isEnd;
    }
};

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    Trie tree(2000006);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tree.add(a[i]);
    }
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        if (tree.search(s)) cout << "YES\n";
        else cout << "NO\n";    
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