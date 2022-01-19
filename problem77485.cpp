#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

void print(const vector<vector<int>> &v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

void rotate(int row1, int col1, int row2, int col2, vector<vector<int>> &v) {
    int leftup = v[row1][col1];
    int rightup = v[row1][col2];
    int leftdown = v[row2][col1];
    int rightdown = v[row2][col2];

    for (int i=0; i<abs(col1-col2); i++) {
        v[row1][col2-i] = v[row1][col2-i-1];
    }
    for (int i=0; i<abs(row1-row2); i++) {
        v[row2-i][col2] = v[row2-i-1][col2];
    }
    for (int i=0; i<abs(col1-col2); i++) {
        v[row2][col1+i] = v[row2][col1+i+1];
    }
    for (int i=0; i<abs(row1-row2); i++) {
        v[row1+i][col1] = v[row1+i+1][col1];
    }

    v[row1][col1+1] = leftup;
    v[row1+1][col2] = rightup;
    v[row2][col2-1] = rightdown;
    v[row2-1][col1] = leftdown;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> arr;
    arr.resize(rows);
    for (int i=0; i<rows; i++) {
        arr[i].resize(columns);
    }
    int cnt = 0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            arr[i][j] = ++cnt;
        }
    }

    vector<int> answer;
    for (int i=0; i<queries.size(); i++) {
        int min_value = rows*columns+1;
        int row1 = queries[i][0]-1;
        int col1 = queries[i][1]-1;
        int row2 = queries[i][2]-1;
        int col2 = queries[i][3]-1;
        rotate(row1, col1, row2, col2, arr);
        for (int row=row1; row<=row2; row++) {
            for (int col=col1; col<=col2; col++) {
                if (row==row1 or row==row2 or col==col1 or col==col2) {
                    min_value = min(min_value, arr[row][col]);
                }
            }
        }
        answer.push_back(min_value);
    }
    return answer;
}

int main() {
    int rows, columns;
    cin >> rows >> columns;

    vector<vector<int>> queries = {{2, 2, 5, 4}};

    solution(rows, columns, queries);
}