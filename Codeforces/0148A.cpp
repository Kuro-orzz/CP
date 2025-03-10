#include <iostream>
using namespace std;

int main(){
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    bool a[100001] = {false};
    for(int i = 1; k*i <= d; i++)
        a[k*i] = true;
    for(int i = 1; l*i <= d; i++)
        a[l*i] = true;
    for(int i = 1; m*i <= d; i++)
        a[m*i] = true;
    for(int i = 1; n*i <= d; i++)
        a[n*i] = true;
    int cnt = 0;
    for(int i = 1; i <= d; i++){
        if(a[i]==true)
            cnt++;
    }
    cout<<cnt;
    return 0;
}