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

int block_sz;
vector<int> a;

struct Query{
    int l, r, x, idx;
    Query(int L, int R, int X, int Idx): l(L), r(R), x(X), idx(Idx) {}
};
 
vector<Query> q;
 
bool cmp(Query a, Query b){
    if(a.l/block_sz != b.l/block_sz)
        return a.l/block_sz < b.l/block_sz;
    return a.r < b.r;
}

const int N = 1e5+6; 
int fre[N], cnt[N];

void insert(int i){
    cnt[fre[a[i]]]--;
    fre[a[i]]++;
    cnt[fre[a[i]]]++;
}
 
void remove(int i){
    cnt[fre[a[i]]]--;
    fre[a[i]]--;
    cnt[fre[a[i]]]++;
}
 
vector<int> query(){
    sort(q.begin(), q.end(), cmp);
    int curL = 0, curR = 0;
    vector<int> ans((int)q.size());
    for(int i = 0; i < (int)q.size(); i++){
        auto [L, R, x, idx] = q[i];
        while(curL < L) remove(curL++);
        while(curL > L) insert(--curL);
        while(curR <= R) insert(curR++);
        while(curR > R + 1) remove(--curR);
        ans[idx] = cnt[x];
    }
    return ans;
}
 
void solve(){
    int n, t; cin >> n >> t;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < t; i++){
        int l, r, x; cin >> l >> r >> x;
        q.emplace_back(l-1, r-1, x, i);
    }
    block_sz = 500;
    vector<int> ans = query();
    for(auto it : ans) cout << it << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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