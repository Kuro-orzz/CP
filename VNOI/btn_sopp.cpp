#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n; cin>>n;
  long long res=1;
  for(int i=2; i<sqrt(n); i++)
    if (n%i==0) res+=i+n/i;
  if (res>n) cout<<1;
  else cout<<0;
  return 0;
}
