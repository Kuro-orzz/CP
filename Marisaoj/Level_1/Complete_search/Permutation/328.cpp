#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<pii> v;

ll mnTime(vector<int> &a){
    ll f = 0, time = 0;
    for(int i = 0; i < v.size(); i++){
        f += v[a[i]].fi;
        if(time < f) time = f;
        time += v[a[i]].se;
    }
    return time;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        pii x; cin >> x.fi >> x.se;
        v.push_back(x);
        a[i] = i;
    }
    ll ans = LLONG_MAX;
    do {
        ans = min(ans, mnTime(a));
    } while(next_permutation(all(a)));
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