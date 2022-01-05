#include <iostream>
#include <algorithm>
using namespace std;

bool is_upper_alphabet(char);
bool is_lower_alphabet(char);
char upper_to_lower(char);
bool is_digit(char);
bool is_special(char);

// 1단계
string step1(string s) {
    string answer = "";
    for (int i=0; i<s.length(); i++) {
        if (is_upper_alphabet(s[i])) {
            answer += upper_to_lower(s[i]);
        }
        else {
            answer += s[i];
        }
    }
    return answer;
}

// 2단계
string step2(string s) {
    string answer = "";
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (is_lower_alphabet(c) or is_digit(c) or is_special(c)) {
            answer += c;
        }
    }
    return answer;
}

// 3단계
string step3(string s) {
    string answer = "";
    for (int i=0; i<s.length(); i++) {
        if (answer=="") {
            answer += s[i];
        }
        else {
            if (!(answer[answer.length()-1]=='.' and s[i]=='.')) {
                answer += s[i];
            }
        }
    }
    return answer;
}


// 4단계
string step4(string s) {
    int start_idx = 0, end_idx = s.length();
    while (s[start_idx]=='.' and start_idx<s.length()) {
        start_idx++;
    }
    while (s[end_idx-1]=='.' and end_idx>0) {
        end_idx--;
    }
    string answer = "";
    for (int i=start_idx; i<end_idx; i++) {
        answer += s[i];
    }
    return answer;
}

// 5단계
string step5(string s) {
    if (s=="") return "a";
    return s;
}

// 6단계
string step6(string s) {
    if (s.length()>=16) {
        string answer = "";
        int end_idx = 15;
        while (s[end_idx-1]=='.' and end_idx>0) {
            end_idx--;
        }
        for (int i=0; i<end_idx; i++) {
            answer += s[i];
        }
        return answer;
    }
    return s;
}

// 7단계
string step7(string s) {
    if (s.length()<=2) {
        string answer = s;
        char c = answer[answer.length()-1];
        while (answer.length()<3) {
            answer += c;
        }
        return answer;
    }
    return s;
}

string solution(string new_id) {
    string answer = step1(new_id);
    answer = step2(answer);
    answer = step3(answer);
    answer = step4(answer);
    answer = step5(answer);
    answer = step6(answer);
    answer = step7(answer);
    return answer;
}

// char c가 알파벳 대문자인지 확인하는 함수
bool is_upper_alphabet(char c) {
    if (c>='A' and c<='Z') return true;
    return false;
}

// char c가 알파벳 소문자인지 확인하는 함수
bool is_lower_alphabet(char c) {
    if (c>='a' and c<='z') return true;
    return false;
}

// 대문자 char c를 소문자로 변환하는 함수
char upper_to_lower(char c) {
    return c-'A'+'a';
}

// char c가 숫자인지 확인하는 함수
bool is_digit(char c) {
    if (c>='0' and c<='9') return true;
    return false;
}

// char c가 허용되는 특수문자인지 확인하는 함수
bool is_special(char c) {
    if (c=='-' or c=='_' or c=='.') return true;
    return false;
}
