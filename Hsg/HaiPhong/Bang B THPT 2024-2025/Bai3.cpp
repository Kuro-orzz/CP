#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int N = 2e5 + 6;
int m, n;
vector<pii> a;
ll group1 = 0, group2 = 0;
int cnt1 = 0, cnt2 = 0;

bool cmp(pii a, pii b) {
    return a.fi - a.se < b.fi - b.se;
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < m+n; i++) {
        pii u;
        cin >> u.fi >> u.se;
        int type; cin >> type;
        if (type == 1) {
            cnt1++; group1 += u.fi;
        } else if (type == 2) {
            cnt2++; group2 += u.se;
        } else if (type == 0) {
            a.push_back(u);
        }
    }
    sort(all(a), cmp);
    for (int i = 0; i < m-cnt1; i++) {
        group1 += a[i].fi;
    }
    for (int i = m-cnt1; i < (int)a.size(); i++) {
        group2 += a[i].se;
    }
    cout << group1 + group2;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
