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

int n, k;
ll a[maxn], pre[maxn];

int bs(int l, int r, ll x){
    int res = 0;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(pre[mid] > x) r = mid-1;
        else if(pre[mid] <= x){
            res = mid;
            l = mid+1;
        }
    }
    return res;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(pre[i] < k)  continue;
        int j = bs(1, i-1, pre[i]-k);
        ans += j+1;
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