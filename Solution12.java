public class Solution12 {
    public static void main(String[] args) {
        int a1 = 3, b1 = 5;
        int a2 = 3, b2 = 3;
        int a3 = 5, b3 = 3;

        System.out.println(solution(a1, b1));
        System.out.println(solution(a2, b2));
        System.out.println(solution(a3, b3));
    }

    public static long solution(int a, int b) {
        long answer = 0;
        if (a>b) {
            int temp = a;
            a = b;
            b = temp;
        }

        for (int i=a; i<=b; i++) {
            answer += i;
        }

        return answer;
    }
}
