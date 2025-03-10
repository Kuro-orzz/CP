#include <iostream>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int a[1000];
    for (int i=0; i<n; i++)
        cin >>a[i];
    int cnt=0;
    for(int i=0; i<k; i++){
        if(a[i]<=0)
            break;
        cnt++;
    }
    if(cnt==k)
        while(a[k]==a[k-1]){
            cnt++;
            k++;
        }
    cout<<cnt;
    return 0;
}