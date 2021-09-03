package programmers;

//1 2 3 4  5  6  7  8  9  10
//1 2 4 11 12 14 21 22 24 41
//11 12 13   14   15   16   17   18   19   20
//42 44 111  112  114  121  124  211  212  214
/*
    16/3 => 5 /3 => 1 /3 =>0
      %3 => 1 %3 => 2
      121
 */
public class level2_124나라의숫자 {
    static String solution(int n) {
        String answer = "";

        while(n!=0){
            int r = n%3;
            n = n/3;
            if(r == 0){
                answer = "4"+answer;
                n--;
            }else if( r == 1){
                answer = "1"+answer;
            }else if(r == 2){
                answer = "2"+answer;
            }
        }

        return answer;
    }
    public static void main(String[] args){
        System.out.println(solution(10));
    }
}
