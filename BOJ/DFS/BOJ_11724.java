package DFS;
/*
    [BOJ] 11724 연결 요소의 개수
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_11724 {
    static int[] visit;
    static int[][] adj;

    static int N;

    static void dfs(int node){

        for(int i=1; i<=N; ++i){
            if(adj[node][i] == 1 && visit[i]==0){
                visit[i] = 1;
                dfs(i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st1 = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st1.nextToken());
        int M = Integer.parseInt(st1.nextToken());

        adj = new int[N+1][N+1];
        visit = new int[N+1];

        for(int i=0; i<M; ++i){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st2.nextToken());
            int v = Integer.parseInt(st2.nextToken());

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        int count =0;

        for(int i=1; i<=N; ++i){
            if(visit[i] == 0){
                dfs(i);
                count++;
            }
        }
        System.out.println(count);

    }
}
