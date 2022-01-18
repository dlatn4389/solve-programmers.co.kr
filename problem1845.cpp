#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int answer = min(size/2, (int)nums.size());
    return answer;
}