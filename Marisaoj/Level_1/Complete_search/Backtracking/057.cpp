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
 
const int N = 10;
int a[N][N], ans[N][N];
unordered_set<int> row[N], col[N], group[N][N];
vector<pii> pos;
bool solved = false;

void res() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans[i][j] = a[i][j];
        }
    }
}

int gr(int i) { return (i-1)/3; }

void add(int i, int j, int x) {
    row[i].insert(x);
    col[j].insert(x);
    group[gr(i)][gr(j)].insert(x);
}

void del(int i, int j, int x) {
    row[i].erase(x);
    col[j].erase(x);
    group[gr(i)][gr(j)].erase(x);
}

void backtrack(int p) {
    if (p == pos.size()) {
        res();
        solved = true;
        return;
    }
    auto [i, j] = pos[p];
    for (int x = 1; x <= 9; x++) {
        if (row[i].count(x) || col[j].count(x)) continue;
        if (group[gr(i)][gr(j)].count(x)) continue;
        a[i][j] = x;
        add(i, j, x);
        backtrack(p+1);
        if (solved) return;
        a[i][j] = 0;
        del(i, j, x);
    }
}

void preprocess() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            row[i].insert(a[i][j]);
            col[j].insert(a[i][j]);
            group[gr(i)][gr(j)].insert(a[i][j]);
        }
    }
}

void solve(){
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> a[i][j];
            if (!a[i][j]) pos.emplace_back(i, j);
        }
    }
    preprocess();
    backtrack(0);
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
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