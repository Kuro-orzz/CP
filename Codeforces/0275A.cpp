#include <iostream>
using namespace std;

int main(){
    int a[3][3];
    int b[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin>>a[i][j];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++){
            b[i][j]=a[i][j];
            if(j-1>=0) b[i][j]+=a[i][j-1];
            if(j+1<=2) b[i][j]+=a[i][j+1];
            if(i-1>=0) b[i][j]+=a[i-1][j];
            if(i+1<=2) b[i][j]+=a[i+1][j];
            if(b[i][j]%2==0) b[i][j]=1;
            else b[i][j]=0;
        }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            cout<<b[i][j];
        cout<<endl;
    }


    return 0;
}