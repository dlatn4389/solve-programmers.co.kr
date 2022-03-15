#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isUpperAlphabet(char c) {
    if (c>='A' and c<='Z') return true;
    return false;
}

bool isLowerAlphabet(char c) {
    if (c>='a' and c<='z') return true;
    return false;
}

void toLower(string &str) {
    for (int i=0; i<str.length(); i++) {
        if (isUpperAlphabet(str[i])) {
            str[i] = str[i]-'A'+'a';
        }
    }
}

void updateTable(vector<vector<int>> &table, string &str) {
    for (int i=1; i<str.length(); i++) {
        if (isLowerAlphabet(str[i-1]) and isLowerAlphabet(str[i])) {
            table[str[i-1]-'a'][str[i]-'a']++;
        }
    }
}

double modNum = 65536;

int solution(string str1, string str2) {
    toLower(str1);
    toLower(str2);

    vector<vector<int>> alphabetTable1(26, vector<int>(26));
    vector<vector<int>> alphabetTable2(26, vector<int>(26));

    updateTable(alphabetTable1, str1);
    updateTable(alphabetTable2, str2);

    int numberOfIntersectionElement = 0;
    int numberOfUnionElement = 0;

    for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
            numberOfIntersectionElement += min(alphabetTable1[i][j], alphabetTable2[i][j]);
            numberOfUnionElement += max(alphabetTable1[i][j], alphabetTable2[i][j]);
        }
    }

    double similarityRate = (double)numberOfIntersectionElement/numberOfUnionElement;
    if (numberOfIntersectionElement==0 and numberOfUnionElement==0) similarityRate=1;

    return (int)(similarityRate*modNum);
}

int main() {
    cout << "Input str1 below" << endl;
    string str1; getline(cin, str1);

    cout << "Input str2 below" << endl;
    string str2; getline(cin, str2);

    cout << endl;
    cout << "************print***************" << endl;
    cout << solution(str1, str2);
}