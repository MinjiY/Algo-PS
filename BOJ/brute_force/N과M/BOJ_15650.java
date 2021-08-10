package brute_force.N과M;
/*
    [BOJ] 15650 N과 M(2)
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;


public class BOJ_15650 {
    static int N, M;
    static int selected[];
    static boolean visit[];
    static StringBuilder sb = new StringBuilder();
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void combination(int indx, int cnt){
        if(cnt == M){
            for(int i=0; i<M; ++i){
                sb.append(selected[i]+" ");
                //System.out.print(selected[i]+" ");
            }
            sb.append("\n");
            //System.out.println();
            return;
        }

        for(int i=indx; i<=N; ++i){
            if(visit[i] == false){
                visit[i] = true;
                selected[cnt] = i;
                combination(i+1,cnt+1);
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

        selected = new int[10];
        visit = new boolean[10];

        combination(1,0);
        System.out.print(sb);
    }
}
