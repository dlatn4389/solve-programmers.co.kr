import java.util.HashMap;

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
        HashMap<String, Integer> counter_participant = new HashMap<>();
        HashMap<String, Integer> counter_completion = new HashMap<>();
        for (String s : participant) {
            if (counter_participant.get(s)==null) {
                counter_participant.put(s, 1);
            }
            else {
                counter_participant.put(s, counter_participant.get(s)+1);
            }
            if (counter_completion.get(s)==null) {
                counter_completion.put(s, 0);
            }
        }
        for (String s : completion) {
            counter_completion.put(s, counter_completion.get(s)+1);
        }

        String answer = null;
        for (String s : counter_participant.keySet()) {
            if (counter_participant.get(s)!=counter_completion.get(s)) {
                answer = s;
                break;
            }
        }
        return answer;
    }
}