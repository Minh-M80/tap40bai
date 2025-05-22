#include<bits/stdc++.h>
using namespace std;

int toNumber(string temp){
    stringstream ss;
    ss<<temp;
    int a;
    ss>>a;
    return a;
}
bool checkInput(string temp,string name){
    stringstream ss(temp);
    string token;
    if(name=="chu"){
        while(ss>>token){
            for(char x:token){
                if(!isalpha(x)){
                    return true;
                }
            }
        }
    }else if(name=="so"){
        int a=toNumber(temp);
        if(a<=0){
            return true;
        }
        for(char x:temp){
            if(!isdigit(x)){
                return true;
            }
        }
    }
    return false;
}
int main(){
int n;
do{
	cin>>n;
}while(n<0 || n>10 || checkInput(n,"so"));
}