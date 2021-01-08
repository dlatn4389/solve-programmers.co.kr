import java.util.Arrays;

public class Solution6 {
    public static void main(String[] args) {
        int[] array = {1,5,2,6,3,7,4};
        int[][] commands = {{2,5,3}, {4,4,1}, {1,7,3}};
        int[] solution = solution(array, commands);

        for (int i=0; i<solution.length; i++) {
            System.out.println(solution[i]);
        }
    }

    public static int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int i, j, k;
        int[] cutted;
        for (int row=0; row<commands.length; row++) {
            i = commands[row][0];
            j = commands[row][1];
            k = commands[row][2];
            if (j>=array.length) {
                cutted = new int[array.length-i+1];
                for (int l=i-1; l<array.length; l++) {
                    cutted[l-i+1] = array[l];
                }
            }
            else {
                cutted = new int[j-i+1];
                for (int l=i-1; l<j; l++) {
                    cutted[l-i+1] = array[l];
                }
            }
            Arrays.sort(cutted);
            answer[row] = cutted[k-1];
        }

        return answer;
    }
}
