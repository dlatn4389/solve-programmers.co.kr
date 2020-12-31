public class Solution4 {
    public static void main(String[] args) {
        int[] answers1 = {1,2,3,4,5};
        int[] answers2 = {1,3,2,4,2};
        solution(answers1);
        solution(answers2);
    }

    public static int[] solution(int[] answers) {
        int length = answers.length;
        int[] scores = {0, 0, 0};

        for (int i=0; i<length; i++) {
            if (answers[i]==i%5+1) {
                scores[0]++;
            }
        }
        for (int index=0; index<length; index++) {
            if (index%2==0) {
                if (answers[index]==2) {
                    scores[1]++;
                }
            }
            else{
                if (index%8==1 || index%8==3) {
                    if (answers[index]==index%8) {
                        scores[1]++;
                    }
                }
                else if (index%8==5) {
                    if (answers[index]==4) {
                        scores[1]++;
                    }
                }
                else if (index%8==7) {
                    if (answers[index]==5) {
                        scores[1]++;
                    }
                }
            }
        }
        for (int index=0; index<length; index++) {
            if (index%10 < 2) {
                if (answers[index]==3) {
                    scores[2]++;
                }
            }
            else if (index%10 < 4) {
                if (answers[index]==1) {
                    scores[2]++;
                }
            }
            else if (index%10 < 6) {
                if (answers[index]==2) {
                    scores[2]++;
                }
            }
            else if (index%10 < 8) {
                if (answers[index]==4) {
                    scores[2]++;
                }
            }
            else if (index%10 < 10) {
                if (answers[index]==5) {
                    scores[2]++;
                }
            }
        }

        int max = scores[0];
        for (int i : scores) {
            if (i>max) {
                max = i;
            }
        }

        int max_count = 0;
        for (int i : scores) {
            if (i==max) {
                max_count++;
            }
        }

        int[] answer = new int[max_count];

        int index = 0;
        for (int i=0; i<3; i++) {
            if (scores[i] == max) {
                answer[index] = i+1;
                index++;
            }
        }

        return answer;
    }
}
