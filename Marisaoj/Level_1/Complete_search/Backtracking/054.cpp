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
 
const int N = 25;
int n, S, w[N], v[N];
ll ans = 0;

void backtrack(int i, int weight, ll val) {
    if (weight > S) return;
    ans = max(ans, val);
    if (i == n) return;
    backtrack(i+1, weight, val);
    backtrack(i+1, weight+w[i], val+v[i]);
}

void solve(){
    cin >> n >> S;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    backtrack(0, 0, 0);
    cout << ans;
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