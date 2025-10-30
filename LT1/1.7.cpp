#include <iostream>
#include <vector>
using namespace std;
#include "1.7.h"

string concat(string str1,string str2){
    string fullname= str1+" "+str2;
    return fullname;
}
/*
int main(){
    string str1;
    string str2;
    cout<<"Enter first name::"<<endl;
    cin>>str1;
    cout<<"Enter last name::"<<endl;
    cin>>str2;
    string res=concat(str1,str2);
    cout<<"Your fullname is::"<<res<<endl;
}*/