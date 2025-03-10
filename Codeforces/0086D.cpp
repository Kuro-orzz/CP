// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

int block_sz;
vector<int> a;

struct Query{
    int l, r, idx;
};

vector<Query> q;

bool cmp1(Query a, Query b){
    if(a.l/block_sz != b.l/block_sz)
        return a.l/block_sz < b.l/block_sz;
    return a.r < b.r;
}

bool cmp2(pair<ll, int> a, pair<ll, int> b){
    return a.se < b.se;
}

void query(){
    sort(q.begin(), q.end(), cmp1);
    int curL = 0, curR = 0;
    ll sum = 0;
    vector<int> fre(1e6+1, 0);
    vector<pair<ll, int>> ans;
    for(int i = 0; i < q.size(); i++){
        while(curL < q[i].l){
            sum -= (2*fre[a[curL]]-1)*a[curL];
            fre[a[curL]]--;
            curL++;
        }
        while(curL > q[i].l){
            curL--;
            sum += (2*fre[a[curL]]+1)*a[curL];
            fre[a[curL]]++;
        }
        while(curR <= q[i].r){
            sum += (2*fre[a[curR]]+1)*a[curR];
            fre[a[curR]]++;
            curR++;
        }
        while(curR > q[i].r+1){
            curR--;
            sum -= (2*fre[a[curR]]-1)*a[curR];
            fre[a[curR]]--;
        }
        ans.push_back({sum, q[i].idx});
    }
    sort(ans.begin(), ans.end(), cmp2);
    for(auto it : ans)
        cout << it.fi << '\n';
}

void solve(){
    int n, t; cin >> n >> t;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < t; i++){
        int l, r; cin >> l >> r;
        q.pb({l-1, r-1, i});
    }
    block_sz = sqrt(n);
    query();
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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