import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Solution3 {
    public static void main(String[] args) {
        String[] participant1 = {"leo", "kiki", "eden"};
        String[] completion1 = {"eden", "kiki"};
        String[] participant2 = {"marina", "josipa", "nikola", "vinko", "filipa"};
        String[] completion2 = {"josipa", "filipa", "marina", "nikola"};
        String[] participant3 = {"mislav", "stanko", "mislav", "ana"};
        String[] completion3 = {"stanko", "ana", "mislav"};

        System.out.println(solution(participant1, completion1));
        System.out.println(solution(participant2, completion2));
        System.out.println(solution(participant3, completion3));
    }

    public static String solution(String[] participant, String[] completion) {
        List<String> participants = new LinkedList<>(Arrays.asList(participant));
        List<String> completions = new LinkedList<>(Arrays.asList(completion));

        while (completions.size()!=0) {
            int index = 0;
            String runner = completions.get(0);

            for (String s : participants) {
                if (s.equals(runner)) {
                    break;
                }
                index++;
            }

            participants.remove(index);
            completions.remove(0);
        }

        String answer = participants.get(0);
        return answer;
    }
}