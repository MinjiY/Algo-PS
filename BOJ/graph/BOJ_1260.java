package graph;
/*
    [BOJ] 1260 DFS와 BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_1260 {
    static int N;
    static int[][] adj;
    static boolean[] visit;
    static StringBuilder sb = new StringBuilder();

    static void dfs(int node){
        for(int i=1; i<=N; ++i){
            if(visit[i] == false && adj[node][i] == 1){
                visit[i] = true;
                sb.append(i+" ");
                //System.out.print(i+" ");
                dfs(i);
            }
        }
    }
    static void bfs(int node){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(node);
        while(!queue.isEmpty()){
            int front = queue.poll();

            if(visit[front] == false){
                visit[front] = true;
                sb.append(front+" ");
                //System.out.print(front+" ");
                for(int i=1; i<=N; ++i){
                    if(visit[i] == false && adj[front][i] == 1){
                        queue.add(i);
                    }
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] cmd = br.readLine().split(" ");
        //        StringTokenizer st = new StringTokenizer(br.readLine());
//
//        N = Integer.parseInt(st.nextToken());
//       int M = Integer.parseInt(st.nextToken());
//       int V = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(cmd[0]);
        int M = Integer.parseInt(cmd[1]);
        int V= Integer.parseInt(cmd[2]);

       adj = new int[N+1][N+1];
       visit= new boolean[N+1];

       for(int i=0; i<M; ++i){
           StringTokenizer st2 = new StringTokenizer(br.readLine());
           int u = Integer.parseInt(st2.nextToken());
           int v = Integer.parseInt(st2.nextToken());
           adj[u][v] = 1;
           adj[v][u] = 1;
       }

       //dfs
        sb.append(V+" ");
        //System.out.print(V+" ");
        visit[V]= true;
        dfs(V);

        Arrays.fill(visit, false);
        //System.out.println();
        sb.append("\n");
        bfs(V);
        System.out.println(sb);
    }
}
