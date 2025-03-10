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
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int odd = 0, even = 0;
    ll mx_o = 0;
    int mx = a[0];
    vi ev;
    for(int i = 0; i < n; i++){
        if(a[i] % 2){
            odd++;
            mx_o = max(mx_o, 1ll*a[i]);
        }
        else{
            even++;
            ev.push_back(a[i]);
        }
        mx = max(mx, a[i]);
    }
    if(!odd || !even){
        cout << "0\n";
        return;
    }
    int ans = even;
    sort(all(ev));
    int i = 0;
    while(i < ev.size() && mx_o > ev[i]){
        mx_o += ev[i];
        i++;
    }
    if(mx % 2 == 0 && mx_o <= ev[ev.size()-1])
        ans++;
    cout << ans << '\n';
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