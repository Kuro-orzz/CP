#include <iostream>
#include <set>

using namespace std;

int main(){
    //freopen("file.inp.c","r",stdin);
    string s; cin >> s;
    set<char> se;
    for(int i=0; i<s.length(); i++){
        se.insert(s[i]);
    }
    if(se.size()%2 != 0)
        cout<< "IGNORE HIM!";
    else
        cout<< "CHAT WITH HER!";
    return 0;
}