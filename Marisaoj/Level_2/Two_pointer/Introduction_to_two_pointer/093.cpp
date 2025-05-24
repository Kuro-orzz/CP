#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5+6;
ll n, x;
vector<pii> a;

int bs(int l, int r, ll x) {
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (a[mid].fi > x) r = mid - 1;
        else if (a[mid].fi < x) l = mid + 1;
        else return mid;
    }
    return -1;
}

void solve(){
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(all(a));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int t = bs(j+1, n-1, x-a[i].fi-a[j].fi);
            if (t != -1) {
                cout << a[i].se+1 << " " << a[j].se+1 << " " << a[t].se+1;
                return;
            }
        }
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