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

const int N = 1e5 + 6;
int n, k, a[N];
double epsilon = 1e-3;

bool check(double avg) {
    double pref[n+1];
    pref[0] = 0;
    double mn = 1e18;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1] - avg;
        if (i >= k) {
            mn = min(mn, pref[i-k]);
            if (pref[i] - mn >= 0) return true;
        }
    }
    return false;
}

double binSearch() {
    double l = 0, r = 1e9;
    while (r-l > epsilon) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return (l+r)/2;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << fixed << setprecision(3) << binSearch();
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