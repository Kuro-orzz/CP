#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e3+6;
int n, x, a[maxn];
map<int, vector<pii>> mp;

void solve() {
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            mp[a[i] + a[j]].push_back({i, j});
        }
    }
    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = x-a[i]-a[j];
            if (!mp.count(t)) continue;
            for (pii it : mp[t]) {
                if (it.fi != i && it.fi != j && it.se != i && it.se != j) {
                    cout << "YES";
                    return;
                }
            }
        }
    }
    cout << "NO";
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