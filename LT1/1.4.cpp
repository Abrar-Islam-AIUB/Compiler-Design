/* Write a program to determine whether the Given Input is Identifier or Not. []
Conditions/convention to detect identifier:

a) The first character should be alphabet characters/underscore (A-Z, a-z, _)
b) From the Second character should be alpha-numeric characters/underscore (A-Z, a-z, _ , 0-9)
*/

#include<iostream>
using namespace std;
#include "1.4.h"

bool DetermineIdentifier(string val){
    for(int i=0;i<val.length();i++){
        if(i==0 &&((char(val[i])>=65 && char(val[i])<=90) || (char(val[i])>=97 && char(val[i])<=122) || char(val[i])==95)){
            for(int j=1;j<val.length();j++){
                if(((char(val[j])>=65 && char(val[j])<=90) || (char(val[j])>=97 && char(val[j])<=122) || char(val[j])==95 || char(val[j])>=48 && char(val[j])<=57)){
                    continue;
                }else{
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
}

/*
int main(){
    string str=" ";
    cout<<"Please enter::"<<endl;
    cin>>str;
    bool res=DetermineIdentifier(str);
    if(res==true){
        cout<<"is an identifier"<<endl;
    }else{
        cout<<"not an identifier"<<endl;
    }
}*/