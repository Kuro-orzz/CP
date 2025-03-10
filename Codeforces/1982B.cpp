#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    ll x, y, k; cin >> x >> y >> k;
    int cnt = 0;
    while(k){
        if(cnt == 0){
            x++;
            k--;
        }
        cnt++;
        ll t = (x%y==0 ? 0 : y-x%y);
        if(x == 1){
            k = k%t;
        }
        if(t <= k){
            x += t;
            k -= t;
        }
        else{
            x += k;
            k = 0;
        }
        while(x % y == 0)
            x /= y;
    }
    cout << x << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}