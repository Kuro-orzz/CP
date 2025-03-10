#include <iostream>
#define ll long long
using namespace std;

void solve(){
    ll t, n, k;
    cin >> t >> k >> n;
    if (t > n){
        cout << 0 <<endl;
    }
    else{
        ll res = 1;
        res += (n-t)/k;
        cout << res <<endl;
    }
}

int main(){
    int m; cin >> m;
    while (m--){
        solve();
    }
    return 0;
}
