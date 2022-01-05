#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>

void print(const vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

// 맞은 갯수를 복권 등수로 반환하는 함수
int convert_cnt_to_ranking(int cnt) {
    int ranks[7] = {6, 6, 5, 4, 3, 2, 1};
    return ranks[cnt];
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int radix[46] = {0,};
    for (int i=0; i<lottos.size(); i++) {
        radix[lottos[i]]++;
    }

    // 가장 숫자가 적게 일치하는 경우 카운트
    int cnt_worst = 0;
    for (int i=0; i<win_nums.size(); i++) {
        if (radix[win_nums[i]]>0) cnt_worst++;
    }

    // 가장 숫자가 많이 일치하는 경우는 cnt_worst에 0의 갯수를 더한 값
    int cnt_best = cnt_worst + radix[0];
    // 만약 6을 초과한 경우, 6으로 조정
    if (cnt_best>6) cnt_best = 6;

    vector<int> answer;
    answer.push_back(convert_cnt_to_ranking(cnt_best));
    answer.push_back(convert_cnt_to_ranking(cnt_worst));

    return answer;
}

int main() {
    vector<int> lottos;
    vector<int> win_nums;
    lottos.resize(6);
    win_nums.resize(6);

    for (int i=0; i<6; i++) {
        cin >> lottos[i];
    }
    for (int i=0; i<6; i++) {
        cin >> win_nums[i];
    }

    print(solution(lottos, win_nums));
}