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
    vi a(n), b(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i = 0; i < n; i++) 
        cin >> b[i];
    sort(all(a));
    sort(all(b));
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]){
            cout << "NO";
            return;
        }
    cout << "YES";
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