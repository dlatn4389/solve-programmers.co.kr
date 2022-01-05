#include <string>
#include <vector>

using namespace std;

bool contain(const vector<int> &numbers, int n) {
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i]==n) return true;
    }
    return false;
}

int solution(vector<int> numbers) {
    int sum = 0;
    for (int i=0; i<10; i++) {
        if (!contain(numbers, i)) {
            sum += i;
        }
    }
    
    return sum;
}