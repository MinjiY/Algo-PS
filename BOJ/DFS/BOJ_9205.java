package DFS;

import java.awt.image.AreaAveragingScaleFilter;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
    [BOJ] 9205 맥주 마시면서 걸어가기
    ** 맨해튼거리 **
    + 플로이드 와샬 풀이
 */
public class BOJ_9205 {
    static int n;
    static ArrayList<Integer>[] adj;
    static int[] visit;
    static int manhattan(Pair p1, Pair p2){
        return Math.abs(p1.x - p2.x)+ Math.abs(p1.y-p2.y);
    }
    static void dfs(int node){
        for(int i=0; i<adj[node].size(); ++i){
            int next = adj[node].get(i);
            if(visit[next] == 0){
                visit[next] = 1;
                dfs(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());


        while((T--) != 0){
            ArrayList<Pair> coord = new ArrayList<>();

            n = Integer.parseInt(br.readLine());
            adj = new ArrayList[n+2];
            visit= new int[n+2];
            for(int i=0; i<n+2; ++i){
                adj[i] = new ArrayList<>();
                StringTokenizer st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y=  Integer.parseInt(st.nextToken());
                coord.add(new Pair(y,x));
            }


            // 맥주 마실수 있는 거리인지 확인
            for(int i=0; i<n+2; ++i){
                for(int j=0; j<n+2; ++j){
                    if(manhattan(coord.get(i),coord.get(j)) <= 50*20 ){
                        adj[i].add(j);
                        adj[j].add(i);
                    }
                }
            }

            // 마실 수 있는 거리에 있는애들 인접리스트로 정리한거 dfs
            dfs(0);
            if(visit[n+1] == 1){
                System.out.println("happy");
            }else{
                System.out.println("sad");
            }

        }
    }
    static class Pair{
        int y;
        int x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
