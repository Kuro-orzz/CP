#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n; cin>>n;
  int k=floor(sqrt(n));
  cout<<k<<endl;
  for (int i=1; i<=k; i++) cout<<i*i<<" ";
  return 0;
}
