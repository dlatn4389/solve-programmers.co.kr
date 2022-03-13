#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int standard = 5;

struct pos {
    int row;
    int col;
    pos(int row, int col): row(row), col(col) {}
};

bool isTable(char s) {
    return s=='O';
}

bool isPartition(char s) {
    return s=='X';
}

bool isPerson(char s) {
    return s=='P';
}

int getDistance(pos pos1, pos pos2) {
    return abs(pos1.row-pos2.row)+abs(pos1.col-pos2.col);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(standard);

    for (int i=0; i<standard; i++) {
        vector<string> place = places[i];
        vector<pos> peoplePosition;
        for (int row=0; row<standard; row++) {
            for (int col=0; col<standard; col++) {
                char thing = place[row][col];
                if (isPerson(thing)) peoplePosition.push_back(pos(row, col));
            }
        }

        bool distancingFailure = false;

        if (peoplePosition.size()>13) distancingFailure = true;

        for (int j=0; j<peoplePosition.size(); j++) {
            if (distancingFailure) break;

            pos pos1 = peoplePosition[j];

            for (int k=j+1; k<peoplePosition.size(); k++) {
                pos pos2 = peoplePosition[k];
                int manhattanDistance = getDistance(pos1, pos2);

                if (manhattanDistance==1) distancingFailure = true;

                else if (manhattanDistance==2) {
                    if (pos1.row==pos2.row) {
                        if (!isPartition(place[pos1.row][pos1.col+1])) distancingFailure = true;
                    }

                    else if (pos1.col==pos2.col) {
                        if (!isPartition(place[pos1.row+1][pos1.col])) distancingFailure = true;
                    }

                    else {
                        if (!isPartition(place[pos1.row][pos2.col]) or !isPartition(place[pos2.row][pos1.col])) distancingFailure = true;
                    }
                }
            }
        }

        if (distancingFailure) answer[i] = 0;
        else answer[i] = 1;
    }
    return answer;
}
