#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x==1){
            cout<< "Hard";
            return 0;
        }
    }
    cout<< "Easy";
    return 0;
}