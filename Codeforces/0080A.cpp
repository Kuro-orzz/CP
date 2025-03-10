#include <iostream>
#include <cmath>
using namespace std;

bool snt(int x){
    if(x<2) return false;
    if(x==2) return true;
    for(int i=2; i<=sqrt(x); i++)
        if(x%i==0) return false;
    return true;
}

int main()
{
    int m,n; 
    cin>>m>>n;
    m++;
    while (snt(m)==false){
        m++;
    }
    if(m==n) cout<<"YES";
    else cout<<"NO";
    return 0;
}