#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>
#include <stack>

int solution(vector<vector<int>> board, vector<int> moves) {
    int size = board.size();
    stack<int> dolls[size+1];

    for (int col=0; col<size; col++) {
        for (int row=size-1; row>=0; row--) {
            if (board[row][col]==0) break;
            dolls[col+1].push(board[row][col]);
        }
    }

    stack<int> basket;
    int answer = 0;

    for (int idx: moves) {
        if (dolls[idx].empty()) continue;
        
        int doll = dolls[idx].top();
        dolls[idx].pop();

        if (basket.empty()) basket.push(doll);
        else {
            if (basket.top()==doll) {
                basket.pop();
                answer += 2;
            }
            else {
                basket.push(doll);
            }
        }
    }
    return answer;
}