#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // progresses 및 speeds 벡터를 큐로 변환
    queue<int> queue_progresses;
    queue<int> queue_speeds;
    for (int i=0; i<progresses.size(); i++) {
        queue_progresses.push(progresses[i]);
    }
    for (int i=0; i<speeds.size(); i++) {
        queue_speeds.push(speeds[i]);
    }

    vector<int> answer;
    while (!queue_progresses.empty()) {
        // 하루에 작업 진행
        // queue의 크기가 중간에 변하므로 반복문 이전에 size 변수에 저장
        int size = queue_progresses.size();
        for (int i=0; i<size; i++) {
            int progress = queue_progresses.front();
            queue_progresses.pop();
            int speed = queue_speeds.front();
            queue_speeds.pop();

            int new_progress = progress + speed;
            queue_progresses.push(new_progress);
            queue_speeds.push(speed);
        }

        // 앞의 작업을 완료했을 때 if문 실행
        if (queue_progresses.front()>=100) {
            int cnt = 0;
            for (int i=0; i<size; i++) {
                if (queue_progresses.front()>=100) {
                    cnt++;
                    queue_progresses.pop();
                    queue_speeds.pop();
                }
                // 앞의 작업이 완료되지 않았을 때 배포할 수 없음
                else {
                    break;
                }
            }
            answer.push_back(cnt);
        }
    }
    return answer;
}

int main() {

}