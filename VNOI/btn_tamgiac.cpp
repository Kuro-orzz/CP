#include <iostream>
using namespace std;

int main()
{
  int n; cin>>n;
  int k=n;
  for (int i=0; i<n; i++)
    {
      for(int j=k; j>0; j--)
        cout<<"*";
      cout<<endl;
      k--;
    }
     
  return 0;
}
