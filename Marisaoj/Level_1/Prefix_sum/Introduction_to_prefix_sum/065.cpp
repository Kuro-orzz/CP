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
int n, a[2*N];
ll pref1[2*N], pref2[2*N], suf1[2*N], suf2[2*N]; 
// pref1: human, pref2: total dist 1,2,...i-1 -> i

ll getPref(int st, int en) {
    return pref2[en] - pref2[st] - pref1[st] * (en - st);
}

ll getSuf(int st, int en) {
    st++, en++;
    return suf2[st] - suf2[en] - suf1[en] * (en - st);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n+1; i <= 2*n; i++) {
        a[i] = a[i-n];
    }
    for (int i = 1; i <= 2*n + 1; i++) {
        pref1[i] = pref1[i-1] + a[i];
        pref2[i] = pref2[i-1] + pref1[i];
    }
    for (int i = 2*n+1; i >= 1; i--) {
        suf1[i] = suf1[i+1] + a[i+1];
        suf2[i] = suf2[i+1] + suf1[i];
    }
    int bonus = n % 2 ? 0 : 1;
    ll ans = 1e18;
    for (int i = n/2; i < n/2 + n; i++) {
        ans = min(ans, getPref(i-n/2+bonus, i)+getSuf(i, i+n/2));
    }
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