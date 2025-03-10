// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 200006

void solve(){
    int n; cin >> n;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    if(mp.size() == 1){
        cout << "NO\n";
        return;
    }
    int t = -1;
    for(auto it : mp){
        if(it.se > mp[t])
            t = it.fi;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        if(a[i] == t){
            cout << "R";
            t = -1;
        }
        else
            cout << "B";
    }
    cout << '\n';
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