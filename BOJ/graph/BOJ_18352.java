package graph;
/*
    [BOJ] 18352 특정 거리의 도시 찾기
 */
import java.io.*;
import java.util.*;

public class BOJ_18352 {
    static int N, M, K;
    static ArrayList<Integer> result = new ArrayList<>();
    static ArrayList<Integer>[] adj;
    static void bfs(int start){
        Queue<NODE> queue = new LinkedList<>();
        queue.add(new NODE(start, 0));
        boolean[] visit = new boolean[N+1];
        visit[start] = true;

        while(!queue.isEmpty()) {
            NODE temp = queue.poll();

            if(temp.cnt == K){
                result.add(temp.node);
            }

            for (int i = 0; i < adj[temp.node].size(); ++i) {
                int next = adj[temp.node].get(i);
                if (visit[next] == false){
                    visit[next] = true;
                    queue.add(new NODE(next,temp.cnt+1));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st1.nextToken());
        M = Integer.parseInt(st1.nextToken());
        K = Integer.parseInt(st1.nextToken());
        adj= new ArrayList[N+1];

        for (int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        for(int i=0; i<M; ++i){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int u= Integer.parseInt(st2.nextToken());
            int v =Integer.parseInt(st2.nextToken());

            // 단방향
            adj[u].add(v);
        }
        bfs(Integer.parseInt(st1.nextToken()));
        if(result.size() == 0){
            System.out.println("-1");
        }
        Collections.sort(result);
        result.forEach((node)->{
            System.out.println(node);
        });


    }
    static class NODE{
        int node;
        int cnt;
        NODE (int node, int cnt){
            this.node = node;
            this.cnt = cnt;
        }
    }
}
