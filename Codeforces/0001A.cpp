#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m; cin>>m;
    int n; cin>>n;
    int a; cin>>a;
    int row,col;
    if(round(m/a)==(double)m/a) row=m/a;
    else row=m/a+1;
    if(round(n/a)==(double)n/a) col=n/a;
    else col=n/a+1;
    cout<<1ll*row*col;
    return 0;
}