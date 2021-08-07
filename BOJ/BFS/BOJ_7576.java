package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/*
    [BOJ] 7576 토마토
 */
public class BOJ_7576 {
    static int N,M;
    static int dy[] = new int[]{0,0,-1,1};
    static int dx[] = new int[]{1,-1,0,0};
    static int[][] map;
    static int[][] visit;
    static Queue<Pair> q = new ArrayDeque<>();

    static void bfs(){
        while(!q.isEmpty()){
            Pair node = q.poll();

            for(int i=0; i<4; ++i){
                int ny = node.y+ dy[i];
                int nx = node.x+dx[i];
                if(ny<0 || nx<0 || ny>=N||nx>=M) continue;

                if(visit[ny][nx] == 0 && map[ny][nx] != -1){
                    visit[ny][nx] = 1;
                    map[ny][nx] = map[node.y][node.x]+1;
                    q.add(new Pair(ny,nx));
                }

            }

        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new int[N+1][M+1];
        visit = new int[N+1][M+1];

        for(int i=0; i<N; ++i){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j=0; j<M; ++j){
                map[i][j] = Integer.parseInt(st2.nextToken());
                if(map[i][j] == 1){
                    q.add(new Pair(i,j));
                    visit[i][j] = 1;
                }
            }
        }
        bfs();
        boolean flag = true;
        int ans = 0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){

                if(map[i][j] == 0){
                    flag = false;
                    break;
                }
                if(ans < map[i][j]){
                    ans = map[i][j];
                }
            }
        }
        if(flag) {
            System.out.println(ans-1);
        }else{
            System.out.println(-1);
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
