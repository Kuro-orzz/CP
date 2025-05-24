#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<int> a;
int n, k;

void backtrack(int idx) {
    if(a.size() == k){
        for(int x : a) cout << x << " ";
        cout << '\n';
        return;
    }
    for(int i = idx; i <= n; i++){
        a.push_back(i);
        backtrack(i+1);
        a.pop_back();
    }
}

void solve() {
    cin >> n >> k;
    backtrack(1);
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