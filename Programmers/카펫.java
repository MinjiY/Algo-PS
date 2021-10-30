package programmers.bruteForce;
/*
    [Programmers] 완전탐색 > 카펫
    https://programmers.co.kr/learn/courses/30/lessons/42842
 */
public class 카펫 {
    static public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];

        //yellow 기준으로
        for(int i=1; i<=yellow; ++i) {
            if (yellow % i != 0) {
                continue;
            }
            int y = i;
            int x = yellow / i;

            if ((y * 2) + ((x + 2) * 2) == brown) {
                answer[0] = x + 2;
                answer[1] = y + 2;
                break;
            }
        }
        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution(24,24));
    }
}
