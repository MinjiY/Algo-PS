package brute_force.N과M;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_15656 {
    static int N,M;
    static int selected[];
    static int arr[];
    static StringBuilder sb = new StringBuilder();

    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void solve(int cnt){
        if(cnt == M){
            for(int i=0; i<M; ++i){
                sb.append(arr[selected[i]]+" ");
            }
            sb.append("\n");
            return;
        }
        for(int i=0; i<N; ++i){
            selected[cnt] = i;
            solve(cnt+1);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());

        arr = new int[N];
        selected = new int[M+1];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i){
            arr[i] = stoi(st.nextToken());
        }
        Arrays.sort(arr);
        solve(0);
        System.out.println(sb);
    }
}
