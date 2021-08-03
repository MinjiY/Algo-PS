package graph;

/*
    [BOJ] 1753 최단경로
 */
import java.io.*;
import java.util.*;

public class BOJ_1753 {
    static ArrayList<NODE>[] adj;
    static int[] dist;
    static boolean[] visit;
    static int N, M;

    static public void bfs(int start){
        //Queue<Integer> queue= new LinkedList<>();
        PriorityQueue<NODE> pq = new PriorityQueue<>();
        pq.add(new NODE(start,0));
        dist[start] = 0;

        while(!pq.isEmpty()){
            NODE temp = pq.poll();
            if(visit[temp.node]){
                continue;
            }
            visit[temp.node] = true;

            for(int i=0; i<adj[temp.node].size(); ++i){
                NODE next = adj[temp.node].get(i);
                // next.v next.w
                if( dist[next.node] > dist[temp.node]+next.w ){
                    dist[next.node] = dist[temp.node]+next.w;
                    pq.add(new NODE(next.node,dist[next.node]));
                }
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new int[N+1];
        adj = new ArrayList[N+1];
        visit = new boolean[N+1];

        for(int i=1; i<=N; ++i){
            adj[i] = new ArrayList<>();
            dist[i] = Integer.MAX_VALUE;
        }

        int K = Integer.parseInt(br.readLine());
        for(int i=0; i<M; ++i){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st2.nextToken());
            int v = Integer.parseInt(st2.nextToken());
            int w = Integer.parseInt(st2.nextToken());

            adj[u].add(new NODE(v,w));
        }
        bfs(K);
        for(int i=1; i<=N; ++i){
            if(dist[i] == Integer.MAX_VALUE){
             //   System.out.println("INF");
                bw.write("INF\n");
            }else {
             //   System.out.println(dist[i]);
                bw.write(String.valueOf(dist[i])+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
    static class NODE implements Comparable<NODE>{
        int node;
        int w;
        NODE(int node, int w){
            this.node = node;
            this.w= w;
        }
        // 간선의 거리가 짧은 것 부터 (오름차순)
        public int compareTo(NODE o){
            return this.w - o.w;
        }
    }
}


