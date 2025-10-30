#include<iostream>
using namespace std;
#include "1.3.h"

int DetermineComment(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '\n') {
            continue;
        } else {
            if (text[i] == '/' && i == 0) {
                if (text[i + 1] == '/') {
                    return 2; 
                }
                else if (text[i + 1] == '*') {
                    for (int j = i + 2; j < text.length() - 1; j++) {
                        if (text[j] == '*' && text[j + 1] == '/') {
                            return 3; 
                        }
                    }
                    return 1; 
                }
                else {
                    return 1; 
                }
            }
        }
    }
    return 1;
}

/*
int main() {
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

    return 0;
}*/
