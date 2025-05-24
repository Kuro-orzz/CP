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
vector<int> a;

int check(ll mx_sum){
    ll sum = 0;
    int cnt = 0;
    for(int &x : a){
        if(x > mx_sum) return -1;
        if(sum + x <= mx_sum)
            sum += x;
        else{
            sum = x;
            cnt++;
        }
    }
    return cnt+1;
}

ll bs(ll l, ll r, int k){
    ll ans = LLONG_MAX;
    while(l <= r){
        ll mid = l+(r-l)/2;
        int t = check(mid);
        if(t == -1) l = mid+1;
        else if(t <= k){
            ans = min(ans, mid);
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}

void solve(){
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << bs(0, 1e15, k);
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