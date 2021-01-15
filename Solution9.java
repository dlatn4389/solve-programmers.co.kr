public class Solution9 {
    public static void main(String[] args) {
        String s1 = "abcde";
        String s2 = "qwer";
        System.out.println(solution(s1));
        System.out.println(solution(s2));
    }

    public static String solution(String s) {
        int length = s.length();
        String answer = "";
        if (length%2==1) {
            int n = length/2;
            answer += s.charAt(n);
            return answer;
        }
        int n = length/2 - 1;
        answer += s.charAt(n);
        answer += s.charAt(n+1);
        return answer;
    }
}
