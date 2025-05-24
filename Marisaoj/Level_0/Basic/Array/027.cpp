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
    vi neg;
    for(int i = 0; i < n; i++)
        if(a[i] < 0)
            neg.push_back(a[i]);
    vi pos;
    for(int i = 0; i < n; i++)
        if(a[i] > 0)
            pos.push_back(a[i]);
    sort(all(neg));
    sort(all(pos), greater<int>());
    int ans = INT_MIN;
    if(neg.size() >= 2)
        ans = max(ans, neg[0]*neg[1]);
    if(pos.size() >= 2)
        ans = max(ans, pos[0]*pos[1]);
    if(neg.size() == 1 && pos.size() == 1)
        ans = max(ans, neg[0]*pos[0]);
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