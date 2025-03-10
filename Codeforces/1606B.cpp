#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll computer_connected=1;
    ll hour=0;
    while(computer_connected < n){
        if(computer_connected <= k){
            computer_connected *= 2;
            hour++;
        }
        else{
            float res = (float)(n-computer_connected)/k;
            if (res != (ll)res)
                res++;
            hour += res;
            break;
        }
    }
    cout << hour << "\n";
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}