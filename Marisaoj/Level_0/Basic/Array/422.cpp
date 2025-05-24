#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    int x, y; cin >> x >> y;
    if(x > y) swap(x, y);
    int dist = 0;
    for(int i = x-1; i < y-1; i++)
        dist += a[i];
    int rev_dist = 0;
    for(int i = y-1; i < n; i++)
        rev_dist += a[i];
    for(int i = 0; i < x-1; i++)
        rev_dist += a[i];
    cout << min(dist, rev_dist);
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