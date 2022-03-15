#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

vector<string> operatorPriorityCase = {"+-*", "+*-", "-+*", "-*+", "*+-", "*-+"};

bool isOperator(char c) {
    if (c=='+' or c=='-' or c=='*') return true;
    return false;
}

ll calculate(string operatorPriority, deque<ll> nums, deque<char> operators) {
    for (int i=0; i<3; i++) {
        nums.push_back(nums.front());
        nums.pop_front();

        int size = operators.size();
        while (size--) {
            char o = operators.front();
            if (o==operatorPriority[i]) {
                ll val1 = nums.back();
                nums.pop_back();
                ll val2 = nums.front();
                nums.pop_front();
                if (o=='*') {
                    nums.push_back(val1*val2);
                }
                else if (o=='+') {
                    nums.push_back(val1+val2);
                }
                else if (o=='-') {
                    nums.push_back(val1-val2);
                }
                operators.pop_front();
            }
            else {
                nums.push_back(nums.front());
                nums.pop_front();
                operators.push_back(operators.front());
                operators.pop_front();
            }
        }
    }
    return abs(nums.front());
}

ll solution(string expression) {
    deque<ll> nums;
    deque<char> operators;

    ll val = 0;
    for (int i=0; i<expression.size(); i++) {
        if (isOperator(expression[i])) {
            nums.push_back(val);
            operators.push_back(expression[i]);
            val = 0;
        }
        else {
            val *= 10;
            val += expression[i]-'0';
        }
    }
    nums.push_back(val);

    ll answer = 0;

    for (int i=0; i<6; i++) {
        answer = max(answer, calculate(operatorPriorityCase[i], nums, operators));
    }

    return answer;
}