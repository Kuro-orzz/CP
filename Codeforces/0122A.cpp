#include <iostream>
using namespace std;

bool luckyNum(int x){
    while(x>0){
        if(x%10!=4 && x%10!=7)
            return false;
        x/=10;
    }
    return true;
}

int main(){
    int n; cin>>n;
    if(luckyNum(n)){
        cout<<"YES";
        return 0;
    }
    if(n%4==0 || n%7==0 || n%44==0 || n%47==0 || n%77==0){
        cout<<"YES";
        return 0;
    }
    if(n%444==0 || n%447==0 || n%474==0 || n%477==0){
        cout<<"YES";
        return 0;
    }
    if(n==744 || n==747 || n==774 || n==777){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}