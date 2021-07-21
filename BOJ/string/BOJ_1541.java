package string;
/*
    [BOJ] 1541 잃어버린 괄호
    + - 괄호
    괄호를 적절히 쳐서 식의 값을 최소로
    0~9의 숫자, 최대 5자리의 숫자, 수는 0으로 시작할 수 있음, 식의 길이는 50보다 작다
 */
import java.io.*;
import java.util.*;


public class BOJ_1541 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String operand = "";
        int sum = 0;
        int ans = 0;
        boolean flag = true;

        for(int i=0; i<s.length(); ++i){
            char c = s.charAt(i);

            if(c >='0' && c<='9') {
                operand += c;
            }else{
                if(c == '-'){
                    /*
                        -를 처음? 10+20-...
                        10-20+....
                     */
                    if( flag == true ){
                        if(sum == 0){
                            ans += Integer.parseInt(operand);
                        }
                        else{
                            sum += Integer.parseInt(operand);
                            ans += sum;
                        }
                        flag = false;
                    }
                    else{
                        sum += Integer.parseInt(operand);
                        ans -= sum;
                    }
                    sum=0;
                    operand="";
                }
                else if(c == '+'){
                    sum += Integer.parseInt(operand);
                    operand="";
                }
            }
        }

        sum += Integer.parseInt(operand);

        if(flag == true) {
            ans += sum;
        }else{
            ans -= sum;
        }

        System.out.println(ans);
    }
}

/*
반례
50-25+60-30
값 : -65

0+50-40-25+40-125
값 : -180

1+2+3+4+5
값 : 15

1-2-3-4-5
값 : -13

9999
값 : 9999

0+9999
값 : 9999

0000-10000+1+0111+0111+01111
값 : -11334

1+2-3+4-5
값 : -9


10-10+10-10+10
값 : -30


50-60+60+70+70-50
값 : -260


00000-1+00000-00005
값 : -6
 */

