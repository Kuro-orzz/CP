#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int sum1,sum2,sum3;
    int x,y,z;
    sum1=sum2=sum3=0;
    for(int i=0; i<n; i++){
        cin>>x>>y>>z;
        sum1+=x;
        sum2+=y;
        sum3+=z;
    }
    if(sum1==0 && sum2==0 && sum3==0)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}