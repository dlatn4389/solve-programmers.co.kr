#include <iostream>
#include <algorithm>
using namespace std;
#include <queue>
#include <vector>

typedef long long ll;

int solution(vector<int> scoville, int k) {
    priority_queue<ll, vector<ll>> pq;
    for (int i=0; i<scoville.size(); i++) {
        pq.push(-scoville[i]);
    }

    int answer = 0;
    while (pq.size()>1 and -pq.top()<k) {
        ll min_spicy = -pq.top();
        pq.pop();
        ll second_min_spicy = -pq.top();
        pq.pop();
        ll mixed = min_spicy + 2*second_min_spicy;
        pq.push(-mixed);
        answer++;
    }

    if (pq.size()==1) {
        if (-pq.top()>=k) return answer;
        return -1;
    }
    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3};
    int k = 11;
    solution(scoville, k);
}