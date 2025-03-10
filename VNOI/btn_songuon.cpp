#include <iostream>
using namespace std;

int tongcs(int x)
{
  int tong=0;
  while (x>0)
    {
      tong+=x%10;
      x=x/10;
    }
  return tong;
}

int main() 
{
  int n; cin>>n;
  int i=n;
  int M=-1;
  while (i>n-100)
    {
      if (tongcs(i)+i==n) M=i;
      i--;
    }
  cout<<M;
  return 0;
}
