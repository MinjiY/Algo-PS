package DP;
/*
    [BOJ] 1912 연속합
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1912 {
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = stoi(br.readLine());
        int MAX = -9999999;
        StringTokenizer st = new StringTokenizer(br.readLine());
        int dp[] = new int[n+1];
        for(int i=1; i<=n; ++i){
            dp[i] = stoi(st.nextToken());
        }
        for(int i=1; i<=n; ++i){
            if((dp[i-1] + dp[i])>0 && dp[i-1]>0 ){
                dp[i] = dp[i-1]+dp[i];
            }
            if(MAX < dp[i]){
                MAX = dp[i];
            }
        }
        System.out.println(MAX);
    }
}
