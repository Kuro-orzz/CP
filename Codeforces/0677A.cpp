#include <iostream>
using namespace std;

int main(){
    int n, h;
    cin >> n >> h;
    int res=0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x<=h)
            res++;
        else
            res+=2;
    }
    cout<<res;
    return 0;
}