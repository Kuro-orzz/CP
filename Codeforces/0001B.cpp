#include <iostream>
#include <cmath>
using namespace std;

bool type(string x)
{
    for(int i=0; i<x.length(); i++)
        if(x[i]=='C' && x[i-1]>='0' && x[i-1]<='9')
            return true;
    return false;
}

int main(){
    int n; cin>>n;
    string col,row;
    while(n--){
        string s; cin>>s;
        if(type(s)){
            col="";
            row="";
            int i=s.length()-1;
            while(s[i]>='0' && s[i]<='9'){
                col=s[i]+col;
                i--;
            }
            int co=stoi(col);
            i=1;
            while(s[i]>='0' && s[i]<='9'){
                row+=s[i];
                i++;
            }
            i=0;
            s="";
            bool check=false;
            while(co>0){
                int x;
                x=(co%(int)pow(26,i+1))/(int)pow(26,i);
                if(x!=0) co-=x*pow(26,i);
                else co-=26*pow(26,i);
                if(x==0 && check==false){
                    s='Z'+s;
                    check=true;
                }
                else if(x!=0 && check==false){
                    s=(char)(x+64)+s;
                }
                else if(x==0 && check==true){
                    s='Z'+s;
                }
                else if(x!=0 && check==true){
                        s=(char)(x+64)+s;
                        check=false;
                }
                i++;
            }           
            s+=row;
            cout<<s<<endl;
        }
        else{
            col="";
            row="";
            int i=s.length()-1;
            while(s[i]>='0' && s[i]<='9'){
                col=s[i]+col;
                i--;
            }
            int co=0;
            int j=0;
            while (i>=0){
               co+=(s[i]-64)*pow(26,j);
                i--;
                j++;
            }
            s="R";
            s+=col;
            s+="C";
            s+=to_string(co);
            cout<<s<<endl;
        }
    }
    return 0;
}
