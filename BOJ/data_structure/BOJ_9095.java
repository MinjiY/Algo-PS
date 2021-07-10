package DataStructure;

import java.io.*;

public class BOJ_9095 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] dp = new int[11];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        int T = Integer.parseInt(br.readLine());

        for (int i = 4; i < 11; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        while((T--)!=0) {
            int n = Integer.parseInt(br.readLine());
            bw.write(String.valueOf(dp[n])+"\n");
        }
        bw.flush();
        bw.close();

    }
}
