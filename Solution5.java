public class Solution5 {
    public static void main(String[] args) {
        int n1 = 5;
        int[] lost1 = {2, 4};
        int[] reserve1 = {1, 3, 5};
        System.out.println(solution(n1, lost1, reserve1));

        int n2 = 5;
        int[] lost2 = {2, 4};
        int[] reserve2 = {3};
        System.out.println(solution(n2, lost2, reserve2));

        int n3 = 3;
        int[] lost3 = {3};
        int[] reserve3 = {1};
        System.out.println(solution(n3, lost3, reserve3));
    }

    public static int solution(int n, int[] lost, int[] reserve) {
        int[] haveClothes = new int[n];
        for (int i=0; i<n; i++) {
            haveClothes[i] = 1;
            if (inArray(i+1, reserve)) {
                haveClothes[i]++;
            }
            if (inArray(i+1, lost)) {
                haveClothes[i]--;
            }
        }

        for (int i=0; i<n; i++) {
            if (i==0) {
                if (haveClothes[i]==2 && haveClothes[i+1]==0) {
                    haveClothes[i]--;
                    haveClothes[i+1]++;
                }
            }
            else if (i==n-1) {
                if (haveClothes[i]==2 && haveClothes[i-1]==0) {
                    haveClothes[i]--;
                    haveClothes[i-1]++;
                }
            }
            else {
                if (haveClothes[i]==2 && haveClothes[i-1]==0) {
                    haveClothes[i]--;
                    haveClothes[i-1]++;
                }
                if (haveClothes[i]==2 && haveClothes[i+1]==0) {
                    haveClothes[i]--;
                    haveClothes[i+1]++;
                }
            }
        }

        int answer = 0;
        for (int i=0; i<n; i++) {
            if (haveClothes[i]==1 || haveClothes[i]==2) {
                answer++;
            }
        }

        return answer;
    }

    public static boolean inArray(int n, int[] array) {
        for (int i=0; i<array.length; i++) {
            if (n==array[i]) {
                return true;
            }
        }
        return false;
    }
}
