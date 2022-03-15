#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> radix(100000+1, 0);

bool isDigit(char c) {
    if (c>='0' and c<='9') return true;
    return false;
}

int maxVal(vector<int>& v) {
    int val = 0;
    for (int i=0; i<v.size(); i++) {
        val = max(val, v[i]);
    }
    return val;
}

vector<int> solution(string s) {
    int val = 0;

    for (char c: s) {
        if (isDigit(c)) {
            val *= 10;
            val += c-'0';
        }
        else {
            if (val>0) {
                radix[val]++;
                val = 0;
            }
        }
    }

    vector<int> answer(maxVal(radix));
    for (int i=1; i<=100000; i++) {
        if (radix[i]!=0) {
            answer[answer.size()-radix[i]] = i;
        }
    }

    return answer;
}

int main() {
    cout << "Input str below" << endl;
    string str; cin >> str;

    cout << endl;
    cout << "***************print************" << endl;
    vector<int> answer = solution(str);

    for (auto i: answer) {
        cout << i << ' ';
    }
}