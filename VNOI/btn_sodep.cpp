#include <iostream>
#include <cmath>
using namespace std;

bool sodep(int x)
{
  bool kt=true;
  while (x>0)
    {
      int res=x%10;
      if (res!=6 && res!=8) kt=false;
      x/=10;
    }
  return kt;
}

int main()
{
  int n; cin>>n;
  if (sodep(n)==true) cout<<"YES";
  else cout<<"NO";
  return 0;
}
