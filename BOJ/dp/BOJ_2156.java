package DP;
/*
    [BOJ] 2156 포도주 시식
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_2156 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[10001];
        int[] dp = new int[10001];
        int N = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; ++i){
            arr[i]=Integer.parseInt(br.readLine());
        }
        dp[1] = arr[1];
        dp[2] = arr[1]+arr[2];

        for(int i=3; i<=N; ++i){
            dp[i] = Math.max(arr[i]+arr[i-1]+dp[i-3], arr[i]+dp[i-2]);
            dp[i] = Math.max(dp[i-1], dp[i]);
        }
        System.out.println(dp[N]);
    }
}
