public class Solution8 {
    public static void main(String[] args) {
        int n1 = 45;
        int n2 = 125;
        System.out.println(solution(n1));
        System.out.println(solution(n2));
    }

    public static int solution(int n) {
        String ternary = decimalToTernary(n);
        String ternary_reverse = new StringBuffer(ternary).reverse().toString();
        int decimal = ternaryToDecimal(ternary_reverse);
        return decimal;
    }

    public static String decimalToTernary(int n) {
        String ternary = "";
        int length = 1;
        while (Math.pow(3, length) <= n) {
            length += 1;
        }
        int value;
        for (int i=length; i>0; i--) {
            value = (int)Math.pow(3, i-1);
            if (value>n) {
                ternary += "0";
            }
            else if (2*value>n) {
                ternary += "1";
                n-=value;
            }
            else {
                ternary += "2";
                n-=2*value;
            }
        }
        return ternary;
    }

    public static int ternaryToDecimal(String n) {
        int answer = 0;
        for (int i=0; i<n.length(); i++) {
            answer += (int)Math.pow(3, n.length()-i-1)*Integer.parseInt(Character.toString(n.charAt(i)));
        }
        return answer;
    }
}
