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
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void permutation(int cnt){
        if(cnt == M){
            for(int i=0; i<M; ++i){
                System.out.print(selected[i]+" ");
            }
            System.out.println();
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
        visit = new boolean[10];
        selected = new int[10];

        permutation(0);

    }
}
