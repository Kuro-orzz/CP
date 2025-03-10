#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(sqrt(a*b/c)+sqrt(b*c/a)+sqrt(c*a/b))*4;
    return 0;
}