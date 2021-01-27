package Level2;
import java.util.*;

public class Printer {
    public static void main(String[] args) {
        int[] priorities1 = {2, 1, 3, 2};
        int location1 = 2;
        int[] priorities2 = {1, 1, 9, 1, 1, 1};
        int location2 = 0;

        System.out.println(solution(priorities1, location1));
        System.out.println(solution(priorities2, location2));
    }

    static int solution(int[] priorities, int location) {
        int length = priorities.length;
        Queue<Integer> locations = new LinkedList<>();
        for (int i=0; i<length; i++) {
            locations.add(i);
        }
        int order = 1;
        while (true) {
            int index = locations.peek();
            if (hasBigger(priorities, length, index)) {
                locations.add(locations.poll());
            }
            else {
                priorities[index] = 0;
                if (index==location) {
                    return order;
                }
                order++;
            }
        }
    }

    static boolean hasBigger(int[] priorities, int length, int index) {
        int value = priorities[index];
        int ind = index+1;
        while (true) {
            if (ind==length) {
                ind = 0;
            }
            if (ind==index) break;
            if (value<priorities[ind]) {
                return true;
            }
            ind++;
        }
        return false;
    }
}
