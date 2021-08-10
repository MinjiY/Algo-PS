package brute_force.N과M;
/*
    [BOJ] 15654 N과 M(5)
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_15654{
    static int N, M;
    static int selected[];
    static boolean visit[];
    static int arr[];
    static StringBuilder sb = new StringBuilder();

    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void solve(int cnt){
        if(cnt == M){
            for(int i=0; i<M; ++i){
                sb.append(arr[selected[i]] + " ");
            }
            sb.append("\n");
            return;
        }
        for(int i=0; i<N; ++i){
            if(visit[i] == false){
                visit[i]= true;
                selected[cnt] = i;
                solve(cnt+1);
                selected[cnt] = 0;
                visit[i] = false;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = stoi(st.nextToken());
        M = stoi(st.nextToken());

        visit = new boolean[N];
        selected = new int[M+1];
        arr = new int [N];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i){
            arr[i] = stoi(st.nextToken());
        }

        Arrays.sort(arr);

        solve(0);
        System.out.println(sb);

    }
}
