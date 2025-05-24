#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

string A, B;
vector<vector<int>> pre;

void solve(){
    cin >> A >> B;
    int n = A.size();
    int m = B.size();
    pre.resize(26, vector<int>(n+1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(j == A[i]-'a') pre[j][i+1] = pre[j][i] + 1;
            else pre[j][i+1] = pre[j][i];
        }
    }
    ll ans = 0;
    for(int i = 0; i < m; i++){
        ans += pre[B[i]-'a'][n-m+i+1]-pre[B[i]-'a'][i];
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