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
int n, ans = 0, need = (1 << 26)-1;
vector<string> a;
vector<int> v;

void backtrack(int i, int val){
    if(i == n){
        if(val == need) ans++;
        return;
    }
    backtrack(i+1, val | v[i]);
    backtrack(i+1, val);
}

void solve(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        string s = string(26, '0');
        for(int j = 0; j < a[i].size(); j++)
            s[a[i][j]-'a'] = '1';
        v.push_back(bitset<26>(s).to_ulong());
    }
    backtrack(0, 0);
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