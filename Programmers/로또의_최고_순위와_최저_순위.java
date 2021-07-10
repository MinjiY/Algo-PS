package programmers.level1;


import java.util.HashSet;
class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int zero = 0;
        int match=0;
        HashSet<Integer> hs = new HashSet<>();
        for(int i=0; i<lottos.length; ++i){
            if(lottos[i] == 0){
                zero++;
            }
            else{
                hs.add(lottos[i]);
            }
        }
        for(int i=0; i<win_nums.length; ++i){
            if(hs.contains(win_nums[i]) == true){
                match++;
            }
        }

        int min = match;
        int max = zero+match;
        int[] answer = {Math.min(7-max,6), Math.min(7-min,6)};

        return answer;
    }
}

