#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a==b)
        cout << 0 <<endl;
    else
        cout << ceil((float)(max(a,b)-min(a,b))/(2*c))<<endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}