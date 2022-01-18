#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <unordered_map>

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> cnt;

    for (string person: participant) {
        cnt[person]++;
    }

    for (string person: completion) {
        cnt[person]--;
    }

    sort(participant.begin(), participant.end());
    participant.erase(unique(participant.begin(), participant.end()), participant.end());

    for (string person: participant) {
        if (cnt[person]>0) {
            return person;
        }
    }
    return "";
}