#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0; i<s.length();i+=2){
        v.push_back(s[i]-'0');
    }
    sort(v.begin(),v.end());
    s="";
    for(int x:v)
        s+=to_string(x)+'+';
    s=s.substr(0,s.length()-1);
    cout<<s;
    return 0;
}