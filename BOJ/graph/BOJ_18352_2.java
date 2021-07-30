package graph;
/*
    [BOJ] 18352 특정 거리의 도시 찾기
    다익스트라로 풀기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_18352_2 {
    static int N, M, K;
    static ArrayList<Integer>[] adj;
    static int[] dist;

    static void bfs(int start){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        dist[start] = 0;

        while(!queue.isEmpty()) {
            int temp = queue.poll();
            for (int i = 0; i < adj[temp].size(); ++i) {
                int next = adj[temp].get(i);
                if (dist[next] == -1){
                    dist[next] = dist[temp]+1;
                    queue.add(next);
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
        dist = new int[N+1];

        for (int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
            dist[i] = -1;
        }

        for(int i=0; i<M; ++i){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int u= Integer.parseInt(st2.nextToken());
            int v =Integer.parseInt(st2.nextToken());
            // 단방향
            adj[u].add(v);
        }
        bfs(Integer.parseInt(st1.nextToken()));
        boolean flag = false;
        for(int i=1; i<=N; ++i){
            if(dist[i] == K ){
                System.out.println(i);
                flag = true;
            }
        }
        if(!flag){
            System.out.println("-1");
        }
    }
}

/*

import java.io.*;
import java.util.*;

public class Main{
    public static int N,M,K,X;
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();

    public static int[] d = new int[300001]; //모든 도시에 대한 최단 거리 초기화

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st=new StringTokenizer(br.readLine()," ");
        N = Integer.parseInt(st.nextToken());   //도시의 개수 = 정점의 개수
        M = Integer.parseInt(st.nextToken());   //도로의 개수 = 간선의 개수
        K = Integer.parseInt(st.nextToken());   //거리 정보 (조건), 최단거리가 K인 모든 도시의 번호 구하기
        X = Integer.parseInt(st.nextToken());   //출발 도시의 번호 = 출발 정점

        //그래프 및 최단 거리 테이블 초기화
        for(int i=0; i<=N; i++){
            graph.add(new ArrayList<Integer>());
            d[i] = -1;
        }

        //도시끼리의 단방향 연결정보
        for(int i=0; i <M; i++){
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
        }

        //출발도시의 거리
        d[X] = 0;

        //BFS
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(X);

        while(!q.isEmpty()){
            int now = q.poll();
            for(int i=0; i<graph.get(now).size(); i++){
                int nextNode = graph.get(now).get(i);

                if(d[nextNode] == -1){
                    d[nextNode] = d[now] +1 ;
                    q.offer(nextNode);
                }
            }
        }

        //최단거리가 K인 모든 도시의 번호를 오름차순 출력
        boolean check = false;
        for(int i =1; i <= N; i++){
            if(d[i] == K){
                System.out.println(i);
                check = true;
            }
        }

        //최단거리가 K인 도시가 없으면 -1출력
        if(!check){
            System.out.println(-1);
        }




    }
}

 */