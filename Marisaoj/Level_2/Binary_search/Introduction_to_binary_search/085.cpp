#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1506;

int n;
int a[maxn];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            ans += upper_bound(a+j+1, a+n+1, a[i]+a[j]-1)-lower_bound(a+j+1, a+n+1, a[j]-a[i]+1);
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