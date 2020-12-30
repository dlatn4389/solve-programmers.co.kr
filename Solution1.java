import java.util.ArrayList;

class Solution1 {
    public static void main(String[] args) {
        int[][] board = {{0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1}};
        int[] moves = {1,5,3,5,1,2,1,4};

        System.out.println(solution(board, moves));
    }

    public static int solution(int[][] board, int[] moves) {
        int answer = 0;
        ArrayList<Integer> arr = new ArrayList<>();
        int depth = board.length;

        for (Integer i : moves) {
            for (int j=0; j<depth; j++) {
                if (board[j][i-1]!=0) {
                    int temp = board[j][i-1];
                    board[j][i-1] = 0;
                    if (arr.size()==0) {
                        arr.add(temp);
                    }
                    else if (arr.get(arr.size()-1)!=temp) {
                        arr.add(temp);
                    }
                    else {
                        arr.remove(arr.size()-1);
                        answer += 2;
                    }
                    break;
                }
            }
        }
        return answer;
    }
}
