public class Solution7 {
    static int[] days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public static void main(String[] args) {
        int a = 5;
        int b = 24;
        System.out.println(solution(a, b));
    }

    public static String solution(int a, int b) {
        int dayPlus = 0;

        for (int i=0; i<12; i++) {
            if ((i+1)==a) {
                dayPlus += b;
                break;
            }
            dayPlus += days[i];
        }
        dayPlus%=7;

        if (dayPlus==0) {
            return "THU";
        }
        else if (dayPlus==1) {
            return "FRI";
        }
        else if (dayPlus==2) {
            return "SAT";
        }
        else if (dayPlus==3) {
            return "SUN";
        }
        else if (dayPlus==4) {
            return "MON";
        }
        else if (dayPlus==5) {
            return "TUE";
        }
        return "WED";
    }
}
