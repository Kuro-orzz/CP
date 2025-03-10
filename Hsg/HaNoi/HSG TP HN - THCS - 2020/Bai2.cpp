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
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            if(c == 'X') v[j]++;
        }
    int mx = 0;
    int cnt = 0;
    for(int x : v){
        if(x > mx){
            mx = x;
            cnt = 0;
        }
        if(x == mx)
            cnt++;
    }
    cout << cnt << " " << mx << '\n';
    vector<int> ans;
    for(int i = 1; i <= n; i++)
        if(v[i] == mx)
            ans.push_back(i);
    sort(all(ans));
    for(int x : ans)
        cout << x << " ";
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
