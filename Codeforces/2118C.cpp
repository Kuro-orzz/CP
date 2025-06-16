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

struct cmp {
    ll nextBit(ll x) {
        return (x | (x + 1)) - x;
    }

    bool operator()(ll a, ll b){
        return nextBit(a) > nextBit(b);
    }
};

ll nextBit(ll x) {
    return (x | (x + 1)) - x;
}

void solve() {
    ll n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<ll, vector<ll>, cmp> pq;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }
    while (k) {
        ll x = pq.top(); pq.pop();
        ll t = (x | (x + 1)) - x;
        if (t <= k) {
            k -= t;
            x = x | (x + 1);
            pq.push(x);
        } else {
            pq.push(x);
            break;
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        ans += __builtin_popcountll(pq.top());
        pq.pop();
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}