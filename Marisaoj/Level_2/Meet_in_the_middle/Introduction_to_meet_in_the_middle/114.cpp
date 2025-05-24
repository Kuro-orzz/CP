#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 40;
int n, a[maxn];
ll sum = 0, ans = (1ull << 63)-1;
vector<ll> L, R;

void MITM(int i, ll sum, int end) {
    if (i >= end) R.push_back(sum);
    else {
        MITM(i+1, sum, end);
        MITM(i+1, sum + a[i], end);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    MITM(0, 0, n/2);
    L = R;
    R.clear();
    MITM(n/2, 0, n);
    sort(all(R));
    for (int i = 0; i < L.size(); i++) {
        auto it = lower_bound(all(R), sum/2-L[i])-R.begin();
        if (it == R.size()) 
            ans = min(ans, abs(sum-2*L[i]-2*R.back()));
        else if (it == 0)
            ans = min(ans, abs(sum-2*L[i]-2*R[it]));
        else ans = min({ans, abs(sum-2*L[i]-2*R[it]), sum-2*L[i]-2*R[it-1]});
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