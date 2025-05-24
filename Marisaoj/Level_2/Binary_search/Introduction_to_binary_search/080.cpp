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

int n, l, r;
ll a[maxn];

int bs(int a[], int lo, int hi, ll x){
    int res = 0;
    while(l <= r){
        int mid = lo+(hi-lo)/2;
        if(a[mid] > x) hi = mid-1;
        else if(a[mid] <= x){
            res = mid;
            lo = mid+1;
        }
    }
    return res;
}

void solve(){
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += upper_bound(a+1, a+n+1, r-a[i])-lower_bound(a+1, a+n+1, l-a[i]);
        if(a[i]+a[i] >= l && a[i]+a[i] <= r) ans--;
    }
    cout << ans/2;
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