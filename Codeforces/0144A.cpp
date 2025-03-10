#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int a[100];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int value_min=a[0];
    int pos_min=0;
    int value_max=a[0];
    int pos_max=0;
    for(int i=0; i<n; i++){
        if (value_min >= a[i]){
            value_min = a[i];
            pos_min = i;
        }
        if (value_max < a[i]){
            value_max = a[i];
            pos_max = i;
        }
    }
    int res=n-1-pos_min+pos_max;
    if (pos_max >= pos_min)
        cout << res-1;
    else cout << res;
    return 0;
}