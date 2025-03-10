#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n; cin >> n;
    int min_val = 1e9;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        int val;
        if(y % 2 == 0)
            val = x + y/2-1;
        else
            val = x + y/2;
        if(val < min_val)
                min_val = val;
    }
    cout << min_val <<endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}