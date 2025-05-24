#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5+6;
int n, S;
ll a[maxn], pre[maxn], c[maxn];

int bs(ll a[], int l, int r, ll x){
    int res = -1;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(a[mid] >= x){
            res = mid;
            r = mid-1;
        }
        else if(a[mid] <= x)
            l = mid+1;
    }
    return res;
}

void solve(){
    cin >> n >> S;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
        c[i] = max(c[i-1], pre[i]);
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
        int pos = bs(c, 0, i-1, pre[i]-S);
        if(pos == -1) continue;
        else ans = max(ans, i-pos);
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