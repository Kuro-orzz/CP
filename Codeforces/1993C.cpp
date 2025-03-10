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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(all(a));
    for(int i = 0; i < n; i++){
        int t = (mx-a[i])/k;
        if(t % 2) t++;
        a[i] += t*k;
        // cout << a[i] << " ";
    }
    int l = a[0], r = a[0]+k-1;
    for(int i = 1; i < n; i++){
        l = max(l, a[i]);
        r = min(r, a[i]+k-1);
    }
    if(l <= r)
        cout << l << '\n';
    else
        cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) 
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}