package programmers.kakao_BlindRecruitment2021;

import java.util.ArrayList;
import java.util.PriorityQueue;

/*
    [Programmers] 2021 Kakao Blind Recruitment
    https://programmers.co.kr/learn/courses/30/lessons/72413

    지점의 갯수 n
    출발지점 s
    A의 도착지점 a
    B의 도착지점 b
 */
public class 합승택시요금 {
    static ArrayList<NODE>[] adj;

    static int[] dijkstra(int n, int s){
        PriorityQueue<NODE> pq = new PriorityQueue<>();
        int[] dist = new int[n+1];
        for(int i=0; i<=n; ++i){
            dist[i] = Integer.MAX_VALUE;
        }

        pq.add(new NODE(s,0));
        dist[s] = 0;
        while(!pq.isEmpty()) {
            NODE cur = pq.poll();
            int node = cur.a;
            int w = cur.b;

            if(dist[node] < w){
                continue;
            }
            for(int i =0; i<adj[node].size(); ++i){
                int next = adj[node].get(i).a;
                int next_w = adj[node].get(i).b;
                if(dist[next] > dist[node]+next_w){
                    dist[next] = dist[node]+next_w;
                    pq.add(new NODE(next,next_w));
                }
            }
        }
        return dist;
    }

    public static int solution(int n, int s, int a, int b, int[][] fares) {
        adj = new ArrayList[fares.length*2];
        for(int i=0; i<fares.length*2; ++i){
            adj[i] = new ArrayList<>();
        }
        for(int i=0; i<fares.length; ++i){
            adj[fares[i][0]].add(new NODE(fares[i][1],fares[i][2]));
            adj[fares[i][1]].add(new NODE(fares[i][0],fares[i][2]));
        }
        int[] dist_s = dijkstra(n,s);
        // 시작지점 => a, 시작지점=>b 의 최소비용의 합 구하기 : 합승 안한 경우
        int cost = dist_s[a]+ dist_s[b];

        int[] dist_a = dijkstra(n,a);
        int[] dist_b =dijkstra(n,b);

        for(int i = 1; i<=n; ++i){
            // 특정 지점까지 합승했을 때 비용과 비교한다.

            if (s != i ){
                // 시작지점을 제외한 다른 지점들
                cost = Math.min(cost, dist_s[i] + dist_a[i] + dist_b[i]);
            }
        }
        return cost;
    }
    public static void main(String[] args){
        int[][] fares = {{4,1,10},{3,5,24},{5,6,2},{3,1,41},{5,1,24},{4,6,50},{2,4,66},{2,3,22},{1,6,25}};
        System.out.println(solution(6,4,6,2,fares));
    }
    static class NODE implements Comparable<NODE>{
        int a;
        int b;
        NODE(int a, int b){
            this.a = a;
            this.b = b;
        }


        public int compareTo(NODE target){
            return this.b-target.b;
        }
    }
}
