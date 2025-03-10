#include <iostream>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int res=a+b+c;
    if(a*b+c>res)
        res=a*b+c;
    if(a+b*c>res)
        res=a+b*c;
    if((a+b)*c>res)
        res=(a+b)*c;
    if(a*(b+c)>res)
        res=a*(b+c);
    if(a*b*c>res)
        res=a*b*c;
    cout<<res;
}

int main(){
    solve();
    return 0;
}