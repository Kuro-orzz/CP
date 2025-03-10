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

struct Oxy{
    ll x, y;
};

double dist(Oxy a, Oxy b){
    return sqrtl((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void solve(){
    Oxy a[4];
    for(int i = 0; i < 4; i++)
        cin >> a[i].x >> a[i].y;
    vector<double> t;
    for(int i = 0; i < 4; i++)
        for(int j = i+1; j < 4; j++)
            t.pb(dist(a[i], a[j]));
    sort(all(t));
    int q; cin >> q;
    Oxy v[4];
    int ans = 0;
    while(q--){
        for(int i = 0; i < 4; i++)
            cin >> v[i].x >> v[i].y;
        vector<double> d;
        for(int i = 0; i < 4; i++)
            for(int j = i+1; j < 4; j++)
                d.pb(dist(v[i], v[j]));
        sort(all(d));
        int check = true;
        for(int i = 0; i < d.size(); i++)
            if(t[i] != d[i])
                check = false;
        if(check)
            ans++;
    }
    cout << ans;
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
