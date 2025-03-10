#include <iostream>
#include <cmath>
using namespace std;

int ucln(int a, int b)
{
  int k=a % b;
  while (k!=0)
    {
      a=b;
      b=k;
      k=a % b;
    }
  return b;
}

int main()
{
  int x; cin>>x;
  int y; cin>>y;
  cout<<abs(ucln(x,y));
  return 0;
}
