#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isBox(int row, int col, vector<string> &board) {
    vector<int> drow = {0, 1, 1};
    vector<int> dcol = {1, 0, 1};

    for (int i=0; i<3; i++) {
        int nrow = row+drow[i];
        int ncol = col+dcol[i];
        if (board[nrow][ncol]!=board[row][col]) return false;
    }
    return true;
}

int solution(int m, int n, vector<string> board) {
    while (true) {
        vector<pair<int, int>> positions;
        for (int i=0; i<m-1; i++) {
            for (int j=0; j<n-1; j++) {
                if (board[i][j]!=' ' and isBox(i, j, board)) {
                    positions.push_back({i, j});
                }
            }
        }
        cout << 6 << endl;
        if (positions.empty()) break;

        for (auto p: positions) {
            int row = p.first;
            int col = p.second;
            board[row][col] = ' ';
            board[row][col+1] = ' ';
            board[row+1][col] = ' ';
            board[row+1][col+1] = ' ';
        }

        for (int col=0; col<n; col++) {
            int bottom = m-1, top = m-1;
            while (top>=0) {
                if (bottom<=top) top--;
                else if (board[top][col]==' ') top--;
                else if (board[bottom][col]!=' ') bottom--;
                else {
                    board[bottom][col] = board[top][col];
                    board[top][col] = ' ';
                    bottom--;
                    top--;
                }
            }
        }
    }

    int answer = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j]==' ') answer++;
        }
    }

    return answer;
}

int main() {
    cout << "Input m below" << endl;
    int m; cin >> m;

    cout << "Input n below" << endl;
    int n; cin >> n;

    vector<string> board(m);
    cout << "Input strs below" << endl;
    for (int i=0; i<m; i++) {
        cin >> board[i];
    }

    cout << endl;
    cout << "******************print*****************" << endl;
    cout << solution(m, n, board);
}