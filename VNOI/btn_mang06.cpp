#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool snt(int x)
{
    if (x<2) return false;
    for(int i=2; i<=sqrt(x); i++)
        if (x%i==0) return false;
    return true;
}

int main()
{
    int n; cin>>n;
    int cnt=0;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int k; cin>>k;
        if (snt(k)==true)
        {
            cnt+=1;
            sum+=k;
        }
    }
    cout<<cnt<<endl<<sum;
    return 0;
}
