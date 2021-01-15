import java.util.*;

public class Solution10 {
    public static void main(String[] args) {
        int[] arr1 = {1, 1, 3, 3, 0, 1, 1};
        int[] arr2 = {4, 4, 4, 3, 3};
        int[] sol1 = solution(arr1);
        int[] sol2 = solution(arr2);

        arrayprinter(sol1);
        arrayprinter(sol2);
    }

    public static int[] solution(int[] arr) {
        int size = 0;

        for (int i=0; i<arr.length; i++) {
            if (arr[i]==-1) {
                continue;
            }
            size += 1;
            for (int j=i+1; j<arr.length; j++) {
                if (i==arr.length-1) {
                    break;
                }
                if (arr[i]==arr[j]) {
                    arr[j] = -1;
                }
                else {
                    break;
                }
            }
        }
        int[] answer = new int[size];
        int index = 0;
        for (int i : arr) {
            if (i!=-1) {
                answer[index++] = i;
            }
        }
        return answer;
    }

    public static void arrayprinter(int[] array) {
        for (int i: array) {
            System.out.print(i + " ");
        }
    }
}
