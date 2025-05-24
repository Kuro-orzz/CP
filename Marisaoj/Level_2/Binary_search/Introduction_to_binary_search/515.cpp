#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int bs(int a[], int l, int r, int x){
    while(l <= r){
        int mid = (l+r)>>1;
        if(a[mid] > x) r = mid-1;
        else if(a[mid] < x) l = mid+1;
        else return mid;
    }
    return -1;
}

void solve(){
    int n, q; cin >> n >> q;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    while(q--){
        int target; cin >> target;
        cout << bs(a, 1, n, target) << '\n';
    }
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