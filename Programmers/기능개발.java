package programmers;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Stack;

/*
    [Programmers] 스택/큐 > 기능개발
    https://programmers.co.kr/learn/courses/30/lessons/42586

    뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발 될 수 있음
    이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됌

    먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수배열 progresses
    각 작업의 개발속도가 적힌 speeds

 */
public class 기능개발 {
    public static int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        Queue<Integer> queue = new ArrayDeque<>();
        for(int i=0; i<progresses.length; ++i){
            int day  = (100-progresses[i])/speeds[i];
            if((100-progresses[i]) % speeds[i] != 0){
                day++;
            }
            if(queue.isEmpty() || (!queue.isEmpty()&& day <= queue.peek())){
                queue.add(day);
            }else {
                int cnt = 0;
                while (!queue.isEmpty()) {
                    queue.poll();
                    cnt++;
                }
                arrayList.add(cnt);
                queue.add(day);
            }
        }
        int cnt =0 ;
        while(!queue.isEmpty()){
            queue.poll();
            cnt++;
        }
        arrayList.add(cnt);

        return arrayList.stream().mapToInt(i->i).toArray();
    }
    public static void main(String[] args){
        // [93, 30, 55]
        // 	[1, 30, 5]
        //int[] progresses = {93,30,55};
        //int[] speeds = {1,30,5};
        int[] progresses = {20, 99, 93, 30, 55, 10};
        int[] speeds = {5, 10, 1, 1, 30, 5};
        //int[] progresses = {95, 90, 99, 99, 80, 99};
        //int[] speeds = {1,1,1,1,1,1};
        int[] ans = solution(progresses, speeds);
        for(int i=0; i<ans.length; ++i){
            System.out.print(ans[i]+" ");
        }
        System.out.println();
    }
}
