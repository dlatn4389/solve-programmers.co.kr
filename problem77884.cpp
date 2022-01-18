#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// true -> 제곱수, false -> 제곱수가 아님
bool square[1001];

int solution(int left, int right) {
    for (int i=1; i<=100; i++) {
        if (i*i>1000) {
            break;
        }
        square[i*i] = true;
    }

    int sum = 0;
    for (int i=left; i<=right; i++) {
        if (square[i]) sum -= i;
        else sum+=i;
    }
    return sum;
}