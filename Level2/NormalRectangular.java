package Level2;

import java.util.Scanner;

public class NormalRectangular {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int W = sc.nextInt();
        int H = sc.nextInt();
        System.out.println(solution(W, H));
    }

    public static long solution(int w, int h) {
        int gcd = gcd(w, h);
        int neww = w/gcd; int newh = h/gcd;
        int answer = 1 + (neww-1) + (newh-1);
        return (long)w*h-answer*gcd;
    }

    public static int gcd(int a, int b) {
        while (b!=0) {
            int temp = a%b;
            a = b;
            b = temp;
        }
        return abs(a);
    }

    public static int abs(int a) {
        if (a<0) return -a;
        return a;
    }
}
