package brute_force.N과M;
/*
    [BOJ] 15649 N과 M(1)
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class BOJ_15649 {
    static int N, M;
    static int selected[];
    static boolean visit[];
    static StringBuilder sb = new StringBuilder();
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void permutation(int cnt){
        if(cnt == M){
            for(int i=0; i<M; ++i){
                sb.append(selected[i]+" ");
                //System.out.print(selected[i]+" ");
            }
            sb.append("\n");
            //System.out.println();
            return;
        }

        for(int i=1; i<=N; ++i){
            if(visit[i] == false){
                visit[i] = true;
                selected[cnt] = i;
                permutation(cnt+1);
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
        visit = new boolean[N+1];
        selected = new int[M+1];

        permutation(0);
        System.out.print(sb);
    }
}
