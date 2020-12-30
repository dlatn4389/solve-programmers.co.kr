import java.util.Set;
import java.util.TreeSet;

class Solution2 {
    public static void main(String[] args) {
        int[] test1 = {2,1,3,4,1};
        int[] test2 = {5,0,2,7};
        int[] sol1 = solution(test1);
        int[] sol2 = solution(test2);

        for (int i : sol1) {
            System.out.print(i + " ");
        }
        System.out.println();
        for (int i : sol2) {
            System.out.print(i+" ");
        }
        System.out.println();
    }

    public static int[] solution(int[] numbers) {
        Set<Integer> sums = new TreeSet<>();
        int length = numbers.length;

        for (int i=0; i<length-1; i++) {
            for (int j=i+1; j<length; j++) {
                sums.add(numbers[i]+numbers[j]);
            }
        }

        int[] answer = new int[sums.size()];

        int index = 0;
        for (Integer i : sums) {
            answer[index++] = i;
        }

        return answer;
    }
}