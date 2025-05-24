#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
ll k;

void solve(){
    ll k; cin >> k;
    if(k < 10){
        cout << k;
        return;
    }
    ll sum = 0;
    ll p1 = 1, p2 = 10, cnt = 1;
    while(sum+(p2-p1)*cnt <= k){
        sum += (p2-p1)*cnt;
        p2 *= 10;
        p1 *= 10;
        cnt++;
    }
    ll ans = p1+(k-sum)/cnt;
    int m = (k-sum)%cnt;
    if(m) cout << to_string(ans)[m-1];
    else cout << (ans-1)%10;
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