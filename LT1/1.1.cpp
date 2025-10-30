//Write a program to determine whether the Given Input is Numeric Constant or Not
#include<iostream>
#include "1.1.h"
using namespace std;

bool DetermineNum(string val){
    for(int i=0;i<val.length();i++){
        if(char(val[i])>=48 && char(val[i])<=57){
            continue;
        }else{
            return false;
        }
    }
    return true;
}
/*
int main(){
    string str=" ";
    cout<<"Please enter::"<<endl;
    cin>>str;
    bool res=DetermineNum(str);
    if(res==true){
        cout<<"Input is numeric constant"<<endl;
    }else{
        cout<<"Not numeric"<<endl;
    }
}
    */