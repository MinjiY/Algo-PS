package programmers;

import java.util.Stack;

/*
    [Programmers] 스택/큐 > 주식가격
    https://programmers.co.kr/learn/courses/30/lessons/42584?language=java

    초 단위로 기록된 주식가격이 담긴 배열 prices
    가격이 떨어지지 않은 기간은 몇초?

 */
public class 주식가격 {
    public static int[] solution(int[] prices) {

        int[] answer = new int[prices.length];

        for(int i=0; i<prices.length; ++i){
            for(int j=i+1; j<prices.length; ++j){
                if(prices[j] >= prices[i]){
                    answer[i]++;
                }
                else{
                    answer[i]++;
                    break;
                }
            }
        }
        return answer;
    }
    public static void main(String[] args){
        int[] prices = {1,2,3,2,3};
        int[] ans = solution(prices);
        for(int i=0; i<ans.length; ++i){
            System.out.print(ans[i]+" ");
        }
        System.out.println();
    }
}
