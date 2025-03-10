#include <iostream>
using namespace std;

bool number_different(int x){
    if(x/1000==x/100%10 || x/1000==x%100/10 || x/1000==x%10)
        return false;
    if(x/100%10==x%100/10 || x/100%10==x%10)
        return false;
    if(x%100/10==x%10)
        return false;
    return true;
}

int main(){
    int year; cin>>year;
    bool check=false;
    while(check==false){
        year++;
        if(number_different(year))
            check=true;
    }
    cout<<year;
    return 0;
}