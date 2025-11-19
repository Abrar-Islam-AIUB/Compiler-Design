#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <cctype>
#include <regex>

using namespace std;

// Function to check if a string is a valid identifier
bool DetermineIdentifier(const string &val) {
    if (val.empty()) return false;

    // First character must be a letter (A-Z, a-z) or underscore (_)
    char first = val[0];
    bool firstValid = (first >= 'A' && first <= 'Z') ||  
                      (first >= 'a' && first <= 'z') || 
                      (first == '_');                

    if (!firstValid) return false;

    // Subsequent characters can be alphanumeric or underscore
    for (int i = 1; i < val.length(); i++) {
        char ch = val[i];
        bool valid = (ch >= 'A' && ch <= 'Z') ||  // Uppercase A-Z
                     (ch >= 'a' && ch <= 'z') || // Lowercase a-z
                     (ch >= '0' && ch <= '9') ||  // Digits 0-9
                     (ch == '_');                // Underscore (_)
        if (!valid) return false;
    }

    return true;
}

// Function to check if the token is a constant (integer, string, or char)
bool isConstant(const string &val) {
    // Check if it's a string constant (enclosed in quotes)
    if ((val.front() == '"' && val.back() == '"') || (val.front() == '\'' && val.back() == '\'')) {
        return true;
    }

    // Check if it's an integer constant (only digits)
    for (char ch : val) {
        if (ch < '0' || ch > '9') return false;
    }
    return true;
}

// Set of keywords (can be expanded as needed)
unordered_set<string> keywords = {"int", "main", "if", "else", "return", "void", "while", "for"};

// Set of operators
unordered_set<string> operators = {"+", "-", "*", "/", "=", "<", ">", "++", "--", "<<", ">>", "&", "|", "!"};

// Set of punctuation marks
unordered_set<string> punctuation = {"(", ")", "{", "}", ";", ",", ".", ":", ";", "<", ">", "++", "--", "<<", ">>"};

// Structure to hold a symbol table entry
struct Symbol {
    string token;
    string type;
};

// Function to split a line into tokens using regular expressions
vector<string> split(const string &str) {
    vector<string> tokens;
    regex tokenRegex(R"([a-zA-Z_][a-zA-Z0-9_]*|[0-9]+|\"[^\"]*\"|\'[^\']*\'|[^\s\w])");
    auto words_begin = sregex_iterator(str.begin(), str.end(), tokenRegex);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back(i->str());
    }

    return tokens;
}

// Function to classify tokens and populate the symbol table
void classifyTokens(const string &line, vector<Symbol> &symbolTable) {
    // Split the line into tokens
    vector<string> tokens = split(line);

    for (const string &token : tokens) {
        // Skip empty tokens
        if (token.empty()) continue;

        // Classify keywords
        if (keywords.find(token) != keywords.end()) {
            symbolTable.push_back({token, "Keyword"});
        }
        // Classify operators
        else if (operators.find(token) != operators.end()) {
            symbolTable.push_back({token, "Operator"});
        }
        // Classify punctuation
        else if (punctuation.find(token) != punctuation.end()) {
            symbolTable.push_back({token, "Punctuation"});
        }
        // Classify identifiers (variables or function names)
        else if (DetermineIdentifier(token)) {
            symbolTable.push_back({token, "Identifier"});
        }
        // Classify constants (integer, string, or char)
        else if (isConstant(token)) {
            symbolTable.push_back({token, "Constant"});
        }
        // If none of the above, treat as other (e.g., unrecognized characters)
        else {
            symbolTable.push_back({token, "Other"});
        }
    }
}

// Function to print the symbol table
void printSymbolTable(const vector<Symbol> &symbolTable) {
    cout << "Symbol Table:" << endl;
    cout << "Token\t\tType" << endl;
    for (const auto &entry : symbolTable) {
        cout << entry.token << "\t\t" << entry.type << endl;
    }
}

int main() {
    // Open the file
    ifstream file("Sample.txt");
    string line;

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Vector to store the symbol table entries
    vector<Symbol> symbolTable;

    // Read the file line by line
    while (getline(file, line)) {
        classifyTokens(line, symbolTable);
    }

    // Print the symbol table after processing the entire file
    printSymbolTable(symbolTable);

    file.close();
    return 0;
}
