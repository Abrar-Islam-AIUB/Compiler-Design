//Write a program to determine whether the Given Input is Operators or Not
#include<iostream>
using namespace std;
#include "1.2.h"

int GetOperators(string val){
    int opCount=0;
    char ops[]={'+','-','*','/','%','='};
    for(int i=0;i<val.length();i++){
        for(int j=0;j<sizeof(ops)/sizeof(ops[0]);j++){
            if(char(val[i])==ops[j]){
                opCount++;
                cout<<"Operator "<<opCount<<':'<<ops[j]<<endl;
            }else{
                continue;
            }
        }
    }
    if(opCount==0){
        cout<<"No operators found"<<endl;
    }else{
        return 0;
    }
}

/*
int main(){
    string str=" ";
    cout<<"Please enter::"<<endl;
    cin>>str;
    int res = GetOperators(str);
}*/