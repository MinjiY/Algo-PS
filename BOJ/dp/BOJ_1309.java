package DP;
/*
    [BOJ] 1309 동물원
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_1309 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] dp = new int[100001][3];
        //0: 안놓는 경우, 1:왼쪽에 놓는 경우 , 2:오른쪽에 놓는 경우
        int N = Integer.parseInt(br.readLine());


        dp[0][0] = 1;
        //dp[1][0] =1;
        //dp[1][1] = 1;
        //dp[1][2] = 1;
        for(int i=1; i<=N; ++i){
            dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%9901;
            dp[i][1] = (dp[i-1][0]+dp[i-1][2])%9901;
            dp[i][2] = (dp[i-1][0]+dp[i-1][1])%9901;
        }
        System.out.println((dp[N][0]+dp[N][1]+dp[N][2])%9901);

    }

}
