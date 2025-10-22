#include <iostream>

using namespace std;

void comment_checker(string s){
    bool flag=false;
    for(int i=0;i<s.length();i++){
        if(s[0]=='/'){
            if(s[1]=='/'){
                cout<<"single line "<<endl;
            }else if (s[1]=='*'){
                flag=true;
            }
        }
}
}

void arith_checker(string s){
    int count=0;
    char arith_arr[]={'+','-','*','/','%','='};
    int n = sizeof(arith_arr) / sizeof(arith_arr[0]);
    for(int i=0;i<s.length();i++){
        for(int j=0;j<n;j++){
            if (s[i]==arith_arr[j]){
                count++;
                cout<<"Operator"<<count<<":"<<arith_arr[j]<<endl;
            }
        }
    }
}

void check_Cons_str(string a){
    for(int i=0;i<a.length();i++){
        if((int)a[i]>=48 && (int)a[i]<=57){
            //cout<<"Numeric constant"<<endl;
            cout<<"Numeric constant"<<endl;
            break;
        }else{
            cout<<"Not numeric"<<endl;
            break;
        }
    }

}
void checkConsChar(char a){
    if ((int)a >= 48 && (int)a<=57){
        cout<<"Numeric constant";
    }else{
        cout<<"Not numeric";
    }
}
int main()
{
    /*
    string a;
    cout<<"Please enter::"<<endl;
    cin>> a;
    //checkConsChar(a);
    //check_Cons_str(a);
    arith_checker(a);
    */
   //task 3
    string text;
    cout << "Enter lines:" << endl;
    cin>>text;
    comment_checker(text);

    }
