package programmers;

import java.util.Arrays;

/*
    [Programmers] 이분탐색 > 입국심사
    https://programmers.co.kr/learn/courses/30/lessons/43238

    입국심사 기다리는 사람 1000 000 000명 이하
    심사관이 한명 심사하는데 걸리는 시간
 */
public class 입국심사 {
    public static long solution(int n, int[] times) {
        long answer = 0;
        //Arrays.sort(times);

        long left = 0;
        long right = (long)n * times[times.length-1]; // 모든 사람이 제일 오래걸리는 심사대에서 모두 심사를 볼 경우

        while(left <= right){
            long mid = (left+right)/2;
            long sum = 0;

            for(int i=0; i<times.length; ++i){
                sum += mid/times[i];
            }
            if(sum < n){
                left = mid+1;
            }
            else{
                right = mid-1;
                answer = mid;
            }
        }
        return answer;
    }

    public static void main(String[] args){
        int times[] = {7,10};
        System.out.println(solution(6, times));
    }
}
