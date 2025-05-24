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

bool check(int d, int k){
    int prev = a[0];
    while(k > 1 && lower_bound(all(a), prev+d) != a.end()){
        prev = *lower_bound(all(a), prev+d);
        k--;
    }
    return k <= 1;
}

int bs(int l, int r, int k){
    int ans = 0;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(check(mid, k)){
            ans = max(ans, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

void solve(){
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    cout << bs(0, 1e9, k);
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