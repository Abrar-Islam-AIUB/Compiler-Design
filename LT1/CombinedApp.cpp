#include<iostream>
#include "1.1.h"
#include "1.2.h"
#include "1.3.h"
#include "1.4.h"
#include "1.5.h"
#include "1.6.h"
#include "1.7.h"

#include<vector>
using namespace std;

int main(){
    int choice ;
    cout<<"Enter from the following::"<<endl;
    cout<<"1. Determine numeric constant"<<endl;
    cout<<"2. Determine operator"<<endl;
    cout<<"3. Determine comment"<<endl;
    cout<<"4. Determine identifier"<<endl;
    cout<<"5. Average value of an array"<<endl;
    cout<<"6. Show largest and smallest in an array"<<endl;
    cout<<"7. Combine into full name"<<endl;

    cin>>choice;

    switch (int(choice))
    {
    case 1:
        {
            string str=" ";
        cout<<"Please enter::"<<endl;
        cin>>str;
        bool res=DetermineNum(str);
        if(res==true){
            cout<<"Input is numeric constant"<<endl;
        }else{
            cout<<"Not numeric"<<endl;
        }
        break;
        }
    case 2:
        {
        string str=" ";
        cout<<"Please enter::"<<endl;
        cin>>str;
        int res = GetOperators(str);
        break;
        }
    case 3:
        {
            string line, text;

        cout << "Enter string(s)::\n";
        while (true) {
            getline(cin, line);
            if (line.empty()) {
                break;
            }
            text += line + "\n";
        }

        int res = DetermineComment(text);

        if (res == 1) {
            cout << "Expression is NOT a comment" << endl;
        } else if (res == 2) {
            cout << "Expression is a SINGLE-LINE comment" << endl;
        } else if (res == 3) {
            cout << "Expression is a MULTI-LINE comment" << endl;
        }
        break;
        }
    case 4:
        {
        string str=" ";
        cout<<"Please enter::"<<endl;
        cin>>str;
        bool res=DetermineIdentifier(str);
        if(res==true){
            cout<<"is an identifier"<<endl;
        }else{
            cout<<"not an identifier"<<endl;
        }
            break;
        }
    case 5:
        {
        int n;
        cout<<"enter size::"<<endl;
        cin>>n;
        int arr[n];
        cout<<"Please enter::"<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        avg(arr,n);
        break;
        }
    case 6:
        {
        int n;
        cout << "Enter size: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Please enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int minVal = returnSmallest(arr, n);
        int maxVal = returnLargest(arr, n);

        cout << "Minimum value::" << minVal << endl;
        cout << "Maximum value::" << maxVal << endl;
        break;
        }
        case 7:
        {
        string str1;
        string str2;
        cout<<"Enter first name::"<<endl;
        cin>>str1;
        cout<<"Enter last name::"<<endl;
        cin>>str2;
        string res=concat(str1,str2);
        cout<<"Your fullname is::"<<res<<endl;
        }
        default:
        break;
        }
        
    }
    

