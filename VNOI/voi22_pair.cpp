/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "pair"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())

#define pii pair<int, int>
#define fi first
#define se second

int n, d, a[2001];

int solve1() {
    sort(a, a+n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            v.push_back(a[i] + a[j]);
        }
    }
    sort(all(v));
    unique(v);
    int ans = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        int target = v[i];
        int upper = target;
        if (i != (int)v.size()-1 && v[i+1] == target + 1) upper += d;
        int l = 0, r = n-1;
        int cnt = 0;
        while (l < r) {
            if (a[l] + a[r] < target) l++;
            else if (a[l] + a[r] > upper) r--;
            else cnt++, l++, r--;
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int solve2() {
    sort(a, a+n);
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            v.push_back({i, j});
        }
    }
    auto cmp = [&](pii x, pii y) {
        if (a[x.fi]+a[x.se] == a[y.fi]+a[y.se]) {
            return x < y;
        }
        return a[x.fi]+a[x.se] < a[y.fi]+a[y.se]; 
    };
    sort(all(v), cmp);
    int ans = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        int l_sum = a[v[i].fi] + a[v[i].se];
        if (i > 0 && a[v[i-1].fi] + a[v[i-1].se] == l_sum) continue;
        int r = i, cnt = 0;
        int r_sum = l_sum;
        vector<int> vis(n+1);
        while (r < (int)v.size() && l_sum + d >= r_sum) {
            if (!vis[v[r].fi] && !vis[v[r].se]) {
                vis[v[r].fi] = vis[v[r].se] = 1;
                cnt++;
            }
            r++;
            if (r < (int)v.size()) r_sum = a[v[r].fi] + a[v[r].se];
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    // int t; cin >> t;
    // while(t--) {
        cin >> n >> d;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (d == 1 && n > 200) cout << solve1();
        else cout << solve2();
    // }
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
