package programmers;
/*
    [Programmers] 연습문제 > 숫자의 표현
    https://programmers.co.kr/learn/courses/30/lessons/12924

    자연수 n을 연속한 자연수들로 표한하는 방법의 갯수
    n 100000 이하

 */
public class 숫자의표현 {
    public static int solution(int n) {
        int answer = 0;
        for(int i=1; i<=n; ++i){
            int num = i;
            int sum = 0;
            while(true){
                sum += num;

                if(sum == n){
                    answer++;
                    break;
                }else if( sum >n){
                    break;
                }
                num++;
            }
        }

        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution(15));
    }
}
