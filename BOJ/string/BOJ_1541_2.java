package string;

/*
    [BOJ] 1541 잃어버린 괄호
    + - 괄호
    괄호를 적절히 쳐서 식의 값을 최소로
    0~9의 숫자, 최대 5자리의 숫자, 수는 0으로 시작할 수 있음, 식의 길이는 50보다 작다
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1541_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringBuilder sb = new StringBuilder();
        StringTokenizer st, stPlus;

        st = new StringTokenizer(br.readLine(), "-");
        int result = 0;

        stPlus = new StringTokenizer(st.nextToken(), "+");
        while (stPlus.countTokens() > 0) {
            result += Integer.parseInt(stPlus.nextToken());
        }

        while (st.countTokens() > 0) {
            int sum = 0;

            stPlus = new StringTokenizer(st.nextToken(), "+");
            while (stPlus.countTokens() > 0) {
                sum += Integer.parseInt(stPlus.nextToken());
            }
            result -= sum;
        }

        System.out.println(result);

    }


}
