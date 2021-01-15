import java.util.Arrays;

public class Solution11 {
    public static void main(String[] args) {
        int[] arr1 = {5, 9, 7, 10};
        int[] arr2 = {2, 36, 1, 3};
        int[] arr3 = {3, 2, 6};

        int[] sol1 = solution(arr1, 5);
        int[] sol2 = solution(arr2, 1);
        int[] sol3 = solution(arr3, 10);

        arrayprinter(sol1);
        arrayprinter(sol2);
        arrayprinter(sol3);
    }

    public static int[] solution(int[] arr, int divisor) {
        int size = 0;
        for (int i : arr) {
            if (i%divisor==0) {
                size++;
            }
        }

        int[] answer = new int[size];
        int index = 0;

        for (int i : arr) {
            if (i%divisor==0) {
                answer[index++] = i;
            }
        }
        if (answer.length==0) {
            answer = new int[1];
            answer[0] = -1;
        }
        Arrays.sort(answer);
        return answer;
    }

    public static void arrayprinter(int[] array) {
        for (int i: array) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
