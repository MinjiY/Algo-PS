package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_2644 {
    static int N;
    static int src, dest;
    static int M;
    static ArrayList<Integer>[] adj;
    static boolean[] visit;

    static int bfs(){
        Queue<Pair> q = new ArrayDeque<>();
        visit[src] = true;
        q.add(new Pair(src,0));
        while(!q.isEmpty()){
            Pair node = q.poll();

            if(node.node == dest){
                return node.cnt;
            }

            for(int i=0; i<adj[node.node].size();++i){
                int next = adj[node.node].get(i);
                if(visit[next] == false){
                    visit[next]=true;
                    q.add(new Pair(next,node.cnt+1));
                }
            }

        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        src = Integer.parseInt(st.nextToken());
        dest = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(br.readLine());
        adj = new ArrayList[N+1];
        for(int i=1; i<=N; ++i){
            adj[i] = new ArrayList<>();
        }
        visit = new boolean[N+1];


        for(int i=0; i<M; ++i){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st2.nextToken());
            int v = Integer.parseInt(st2.nextToken());
            adj[u].add(v);
            adj[v].add(u);
        }

        System.out.println(bfs());


    }
    static class Pair{
        int node;
        int cnt;
        Pair(int node, int cnt){
            this.node= node;
            this.cnt = cnt;
        }
    }
}
