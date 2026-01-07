#include <iostream>
using namespace std;

int transition(int state, char c) {
    switch(state) {
        case 0:
            if(c=='b'){
                return 1;
            }
            else{return -1;}
        case 1:
            if(c=='a'){
                return 2;
            }
            else if(c=='b'){
                return 4;
            }
            else{
                return -1;
            }
        case 2:
            if(c=='a'){
                return 8;
            }
            else if(c=='b'){
                return 3;
            }
            else{
                return -1;
            }
        case 3:
            if(c=='a'){
                return 12;
            }
            else if(c=='b'){
                return 15;
            }
            else{
                return -1;
            }
        case 4:
            if(c=='a'){
                return 5;
            }
            else{
                return -1;
            }
        case 5:
            if(c=='a'){
                return 6;
            }
            else if(c=='b'){
                return 7;
            }
            else{
                return -1;
            }
        case 6:
            if(c=='a'){
                return 9;
            }
            else if(c=='b'){
                return 4;
            }
            else{
                return -1;
            }
        case 7:
            if(c=='a'){
                return 9;
            }
            else if(c=='b'){
                return 6;
            }
            else{
                return -1;
            }
        case 8:
            if(c=='a'){
                return 9;
            }
            else if(c=='b'){
                return 4;
            }
            else{
                return -1;
            }
        case 9:
            if(c=='a'){
                return 9;
            }
            else if(c=='b'){
                return 4;
            }
            else{
                return -1;
            }
        case 10:
            if(c=='a'){
                return 13;
            }
            else if(c=='b'){
                return 11;
            }
            else{
                return -1;
            }
        case 11:
            if(c=='a'){
                return 10;
            }
            else if(c=='b'){
                return 4;
            }
            else{
                return -1;
            }
        case 12:
            if(c=='a'){
                return 13;
            }
            else if(c=='b'){
                return 11;
            }
            else{
                return -1;
            }
        case 13:
            if(c=='a'){
                return 8;
            }
            else if(c=='b'){
                return 4;
            }
            else{
                return -1;
            }
    }
    return -1; 
}

bool isFinal(int state) {
    return state==1||state==2||state==3||state==6||
           state==7||state==8||state==10||state==11||state==12||state==13;
}

int main() {
    string input;
    cout << "Enter string over {a,b}: ";
    cin >> input;

    int current=0; 

    for(char ch : input) {
        current = transition(current, ch);
        if(current == -1) { cout << "Invalid input\n"; return 0; }
    }

    if(isFinal(current)) cout << "string is valid\n";
    else cout << "string is invalid\n";

    return 0;
}
