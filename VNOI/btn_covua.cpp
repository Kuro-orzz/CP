#include <iostream>
using namespace std;

int main()
{
  int n; cin>>n;
  for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=n; j++)
        {
          if (i%2==1)
          {
            if (j%2==1) cout<<"W";
              else cout<<"B";
          }
          if (i%2==0)
          {
            if (j%2==1) cout<<"B";
              else cout<<"W";
          }
        }
      cout<<endl;
    }
  return 0;
}
