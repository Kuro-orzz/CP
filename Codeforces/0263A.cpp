#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int i=0;
    int a; cin>>a;
    while(a!=1){
        cin>>a;
        i++;
    }
    cout<<abs(i/5+1-3)+abs(i%5+1-3);
    return 0;
}