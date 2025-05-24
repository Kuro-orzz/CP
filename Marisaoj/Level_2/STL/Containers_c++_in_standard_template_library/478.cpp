#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1506;
int n, q;
vector<int> a;

void solve(){
    cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            a.push_back(x);
        }
        else if(type == 2){
            a.pop_back();
        }
        else{
            int idx; cin >> idx;
            cout << a[idx-1] << '\n';
        }
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