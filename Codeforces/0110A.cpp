#include <iostream>
using namespace std;

bool nearlyLuckyNum(long long x){
    int i=0;
    while(x>0){
        if(x%10==4 || x%10==7) i++;
        x/=10;
    }
    if(i==4 || i==7) return true;
    return false;
}

int main(){
    long long n; cin>>n;
    if(nearlyLuckyNum(n)) cout<<"YES";
    else cout<<"NO";
    return 0;
}
