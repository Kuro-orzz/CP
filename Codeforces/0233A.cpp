#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[10000];
    if(n%2!=0){
        cout<<-1;
        return 0;
    }
    for(int i=1; i<=n; i++) a[i]=i;
    for(int i=1; i<=n; i+=2) swap(a[i],a[i+1]);
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    return 0;
}