package programmers;
/*
    [Programmers] level2 Heap 더맵게
 */
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class level2_더맵게 {
    static int solution(int[] scoville, int K) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0; i<scoville.length; ++i){
            pq.add(scoville[i]);
        }
        while(true){
            if(!pq.isEmpty() && pq.peek() >= K ){
                break;
            }
            if(pq.size() < 2){
                if(!pq.isEmpty() && pq.peek()<K){
                    answer = -1;
                }
                break;
            }
            int first = pq.poll();
            int second = pq.poll();

            int third = first + (second*2);
            pq.add(third);
            answer++;
        }

        return answer;
    }
    public static void main(String[] args){
        int[] scoville1 = {1,2,3,9,10,12};
        int[] scoville2 = {2};

        int K = 7;
        solution(scoville2, K);
    }
}
