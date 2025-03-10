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

const int N = 1e7+1;
vector<int> nt;

void sieve(){
    nt.resize(N+1, 1);
    nt[0] = nt[1] = 0;
    for(int i = 2; i*i <= N; i++)
        if(nt[i])
            for(int j = i*i; j <= N; j+=i)
                nt[j] = 0;
}

void solve(){
    int n; cin >> n;
    vector<int> cnt(3, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 1)
            cnt[1]++;
        else
            cnt[2]++;
    }
    sieve();
    vi v = {0};
    for(int i = 2; i < N; i++){
        if(nt[i])
            v.pb(i);
    }
    int i = 1;
    while(cnt[1] || cnt[2]){
        int tmp = v[i]-v[i-1];
        int sum = 0;
        for(int j = 0; j < min(cnt[2], tmp/2); j++)
            cout << "2 ";
        sum = 2*min(cnt[2], tmp/2);
        cnt[2] -= min(cnt[2], tmp/2);
        for(int j = 0; j < min(cnt[1], tmp-sum); j++)
            cout << "1 ";
        cnt[1] -= min(cnt[1], tmp-sum);
        i++;
    }
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