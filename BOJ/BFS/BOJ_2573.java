package BFS;
/*
    [BOJ] 2573 빙산
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_2573 {
    static int N,M;
    static int map[][];
    static int visit[][];
    static int dy[] = new int[]{0,0,-1,1};
    static int dx[] = new int[]{-1,1,0,0};

    static void printMap(){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
               System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
    }
    static void bfs(int y, int x){
        Queue<Pair> q= new ArrayDeque<Pair>();
        q.add(new Pair(y,x));
        visit[y][x] = 1;

        while(!q.isEmpty()){
            Pair node = q.poll();

            for(int i=0; i<4; ++i){
                int ny = node.y + dy[i];
                int nx = node.x + dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(visit[ny][nx]  == 0 && map[ny][nx] != 0) {
                    visit[ny][nx] = 1;
                    q.add(new Pair(ny, nx));
                }
            }

        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N+1][M+1];
        visit = new int[N+1][M+1];

        for(int i=0; i<N; ++i){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j=0; j<M; ++j){
                map[i][j] = Integer.parseInt(st2.nextToken());
            }
        }

        boolean flag = true;
        int ans =0;
        while(flag) {
            /* 빙산 갯수 세기 */

            //빙산 갯수세는 임시cnt
            int iceCnt = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (visit[i][j] == 0 && map[i][j] != 0) {
                        iceCnt++;
                        bfs(i, j);
                    }
                    if (iceCnt >= 2) {
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(!flag){
                break;
            }
            for(int i=0; i<visit.length; ++i){
                Arrays.fill(visit[i],0);
            }
            ans++;

            /* 빙산 깎기 */
            boolean iceFlag = false;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    int cnt = 0;
                    if (map[i][j] != 0) {
                        iceFlag = true;
                        visit[i][j] = 1;
                        for (int k = 0; k < 4; ++k) {
                            int ny = i + dy[k];
                            int nx = j + dx[k];
                            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                            if (map[ny][nx] == 0 && visit[ny][nx] == 0) {
                                cnt++;
                            }
                        }
                    }
                    map[i][j] = Math.max(map[i][j] - cnt, 0);
                }
            }
            if(!iceFlag){
                //빙산이 없어
                ans =0;
                break;
            }
            for(int i=0; i<visit.length; ++i){
                Arrays.fill(visit[i],0);
            }

        }

        System.out.println(ans);

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
