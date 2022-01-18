#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void print(const vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

int bfs(int row, int col, int &number_of_area,vector<vector<int>> &picture) {
    if (picture[row][col]==0) return 0;
    number_of_area++;

    int row_size = picture.size();
    int col_size = picture[0].size();

    int size_of_area = 0;
    int color = picture[row][col];
    picture[row][col] = 0;

    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        size_of_area++;

        for (int i=0; i<4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow<0 or ncol<0 or nrow>=row_size or ncol>=col_size) continue;
            if (picture[nrow][ncol]==color) {
                picture[nrow][ncol] = 0;
                q.push({nrow, ncol});
            }
        }
    }
    return size_of_area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, number_of_area, picture));
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = {{1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3}};

    print(solution(m, n, picture));
}