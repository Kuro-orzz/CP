#include <iostream>
#define ll long long

using namespace std;

int main(){
    //freopen("file.inp.c","r",stdin);
    int a, b;
    cin >> a >> b;
    int cnt=0;
    while (a <= b){
        a*=3;
        b*=2;
        cnt++;
    }
    cout << cnt;
    return 0;
}