#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int func(vector<int> numbers, int target, int temp_sum, int idx) {
    if (idx==numbers.size()) {
        if (temp_sum==target) return 1;
        return 0;
    }

    int ret = 0;
    int value = numbers[idx];

    ret += func(numbers, target, temp_sum+value, idx+1);
    ret += func(numbers, target, temp_sum-value, idx+1);

    return ret;
}

int solution(vector<int> numbers, int target) {
    return func(numbers, target, 0, 0);
}