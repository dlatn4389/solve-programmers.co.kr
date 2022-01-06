#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>

bool is_prime(int n) {
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

void combination(int start, vector<int> &nums, vector<int> &comb, int &cnt) {
    if (comb.size()==3) {
        int sum = 0;
        for (int i: comb) {
            sum += i;
        }
        if (is_prime(sum)) cnt++;
        return;
    }
    for (int i=start; i<nums.size(); i++) {
        comb.push_back(nums[i]);
        combination(i+1, nums, comb, cnt);
        comb.pop_back();
    }
}

int solution(vector<int> nums) {
    int cnt = 0;
    vector<int> comb;
    combination(0, nums, comb, cnt);
    return cnt;
}