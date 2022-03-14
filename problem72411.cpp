#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <unordered_map>

unordered_map<string, int> um;

void combination(int start, int chosen, string &order, string temp) {
    if (chosen==0) {
        sort(temp.begin(), temp.end());
        um[temp]++;
        return;
    }

    for (int i=start; i<order.length(); i++) {
        temp.push_back(order[i]);
        combination(i+1, chosen-1, order, temp);
        temp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (string order: orders) {
        for (int length: course) {
            if (length<=order.length()) {
                combination(0, length, order, "");
            }
        }
    }

    vector<string> answer;
    for (int length: course) {
        vector<string> temp;
        int maxVal = 0;

        for (auto p: um) {
            if (p.first.length()==length) {
                if (maxVal==p.second and maxVal>=2) {
                    temp.push_back(p.first);
                }
                else if (maxVal<p.second) {
                    maxVal = p.second;
                    temp.clear();
                    if (maxVal>=2) temp.push_back(p.first);
                }
            }
        }

        answer.insert(answer.end(), temp.begin(), temp.end());
    }

    sort(answer.begin(), answer.end());

    return answer;
}
