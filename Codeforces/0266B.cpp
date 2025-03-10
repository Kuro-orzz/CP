#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin>>n;
    int sec; cin>>sec;
    string s; cin>>s;
    for(int i=0; i<sec; i++)
        for(int j=0; j<s.length(); j++){
            if(s[j]=='B' && s[j+1]=='G' && j+1<s.length()){
                swap(s[j],s[j+1]);
                j++;
            }
        }
    cout<<s;
    return 0;
}