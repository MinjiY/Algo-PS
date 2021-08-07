package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_2667 {
    static int[][] map;
    static boolean[][] visit;
    static int N;
    static int dy[] = new int[]{0,0,-1,1};
    static int dx[] = new int[]{-1,1,0,0};
    static ArrayList<Integer> danji = new ArrayList<>();
    static void bfs(int y, int x){
        Queue<Pair> q = new ArrayDeque<Pair>();
        q.add(new Pair(y,x));
        int cnt = 1;
        visit[y][x] = true;
        while(!q.isEmpty()){
            Pair node = q.poll();
            for(int i =0; i<4; ++i){
                int ny = node.y + dy[i];
                int nx = node.x + dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
                if(visit[ny][nx] == false && map[ny][nx] == 1){
                    visit[ny][nx] = true;
                    cnt++;
                    q.add(new Pair(ny,nx));
                }
            }
        }
        danji.add(cnt);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int danji_cnt = 0;
        map = new int[N+1][N+1];
        visit= new boolean[N+1][N+1];

        for(int i=0; i<N; ++i){
            String temp = br.readLine();
            for(int j=0; j<N; ++j){
                map[i][j] = temp.charAt(j)-'0';
            }
        }

        for(int i=0; i<N; ++i){
            for(int j=0; j<N;++j){
                if(visit[i][j] == false && map[i][j] == 1){
                    danji_cnt++;
                    bfs(i,j);
                }
            }
        }
        System.out.println(danji_cnt);
        Collections.sort(danji);
        for(int i=0; i<danji.size(); ++i){
            System.out.println(danji.get(i));
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
