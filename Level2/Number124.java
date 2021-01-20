package Level2;

import java.util.Scanner;

public class Number124 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(solution(n));
    }

    public static String solution(int n) {
        int length = 0;
        for (int i=1; i<20; i++) {
            if (geoSeriesSum(3, 3, i)>=n) {
                length = i;
                break;
            }
        }
        int start = geoSeriesSum(3, 3, length-1)+1;
        //System.out.println(start);
        int end = geoSeriesSum(3, 3, length);
        //System.out.println(end);
        String answer = "";
        while (answer.length()!=length) {
            int sub = (end-start+1)/3;
            //System.out.println(sub);
            if (n<start+sub) {
                answer += "1";
                end = start+sub-1;
            }
            else if (n<start+2*sub) {
                answer += "2";
                start = start + sub;
                end = start + 2*sub - 1;
            }
            else {
                answer += "4";
                start = start + 2*sub;
            }
        }
        return answer;
    }

    public static int geoSeriesSum(int a1, int r, int n) {
        int answer = (int)Math.pow(r, n) - 1;
        answer *= a1;
        answer /= r-1;
        return answer;
    }
}
