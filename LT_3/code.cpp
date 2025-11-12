#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool DetermineIdentifier(string val){
    for(int i=0;i<val.length();i++){
        if(i==0 &&((char(val[i])>=65 && char(val[i])<=90) || (char(val[i])>=97 && char(val[i])<=122) || char(val[i])==95) || !char(val[i])==32){
            for(int j=1;j<val.length();j++){
                if(((char(val[j])>=65 && char(val[j])<=90) || (char(val[j])>=97 && char(val[j])<=122) || char(val[j])==95 || char(val[j])>=48 && char(val[j])<=57) || char(val[i])==32){
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

int main() {
    ifstream file("sample.txt"); // open 
    string line;

    if (!file) {
        cerr << "Error opening file!" << endl;
    }
    int count=1;

    while (getline(file, line)) { 
        bool res=DetermineIdentifier(line);
        if(res==true){
            cout<<"Identifier is valid at line "<<count<<endl;
            count++;
        }else{
            cout<<"Identifier is invalid at line "<<count<<endl;
            count++;
        }
        
    }

    file.close(); 
    return 0;
}
