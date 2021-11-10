package graph.topologicalSorting;
/*
    [BOJ] 2252 줄 세우기
    https://www.acmicpc.net/problem/2252

    위상정렬 풀이
    1. 인접리스트, indegree 배열만들기
    2. indegree가 0인 노드 queue에 넣기, 위상정렬 결과에 추가
    3. while queue돌면서 위상정렬 결과에 추가, 해당 정점으로 연결된 노드의 indegree감소
    4. 감소시킬때 0이면 queue에 넣기

 */

import java.io.*;
import java.sql.Array;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_2252 {
    static ArrayList<Integer> []adj;
    static int[] indeg = new int[32001];
    static int N, M;
    static ArrayList<Integer> result = new ArrayList<>();
    static int stoi(String str){
        return Integer.parseInt(str);
    }


    static void topo_sort(){
        Queue<Integer> q  = new ArrayDeque<>();

        for(int i=1; i<=N; ++i){
            if(indeg[i] == 0){
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int cur = q.poll();

            result.add(cur);
            for(int i = 0; i< adj[cur].size(); ++i){
                int next = adj[cur].get(i);
                indeg[next]--;
                if(indeg[next] == 0){
                    q.add(next);
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());

        adj = new ArrayList[N+1];

        for(int i=0; i<N+1; ++i){
            adj[i] = new ArrayList<>();
        }
        for(int i =0; i<M; ++i){
            int u , v;
            st = new StringTokenizer(br.readLine());
            u = stoi(st.nextToken());
            v = stoi(st.nextToken());

            adj[u].add(v);
            indeg[v]++;
        }
        topo_sort();
        for(int i=0; i<result.size(); ++i){
            bw.write(String.valueOf(result.get(i))+" ");
        }
        bw.flush();
        bw.close();
    }
}
