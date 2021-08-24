package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_14442 {
    static int map[][];
    static int visit[][][];
    static int N,M,K;
    static int[] dy = {0,0,-1,1};
    static int[] dx= {1,-1,0,0};
    static int ans = Integer.MAX_VALUE;

    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void printMap(){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
    static void bfs(){
        Queue<NODE> q = new ArrayDeque<>();
        q.add(new NODE(0,0,0,0));
        visit[0][0][0]=1;

        while(!q.isEmpty()){
            NODE node = q.poll();

            if(node.y == (N-1) && node.x == (M-1)){
                if(ans > node.cnt+1){
                    ans = node.cnt+1;
                }
                continue;
            }
            for(int i=0; i<4; ++i){
                int ny= node.y +dy[i];
                int nx= node.x + dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;

                if(map[ny][nx] == 1){
                    if(node.wall< K &&visit[ny][nx][node.wall]==0){
                        visit[ny][nx][node.wall+1] = 1;
                        q.add(new NODE(ny, nx, node.cnt + 1, node.wall + 1));
                    }
                }else if(map[ny][nx] == 0 && visit[ny][nx][node.wall] == 0){

                        visit[ny][nx][node.wall] = 1;
                        q.add(new NODE(ny, nx, node.cnt + 1, node.wall));

                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());
        K = stoi(st.nextToken());
        map = new int[N][M];
        visit=new int[N][M][K+1];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            String temp = st.nextToken();
            for(int j=0; j<M; ++j){
                map[i][j] = temp.charAt(j)-'0';
            }
        }

        bfs();
        if(ans ==Integer.MAX_VALUE){
            System.out.println(-1);
        }
        else{
            System.out.println(ans);
        }


    }
    static class NODE{
        int y;
        int x;
        int cnt;
        int wall;
        NODE(int y, int x, int cnt, int wall){
            this.y = y;
            this.x = x;
            this.cnt = cnt;
            this.wall =wall;
        }
    }
}
