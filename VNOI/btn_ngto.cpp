#include <iostream>
#include <cmath>
using namespace std;

bool snt(int n)
{
  bool kt=true;
  if (n<2) return 0;
  for (int i=2; i<=floor(sqrt(n)); i++)
    if (n%i==0) return 0;
  return kt;
}

int main()
{
  int n; cin>>n;
  if (snt(n)==1) cout<<"YES";
  else cout<<"NO";
  return 0;
}
