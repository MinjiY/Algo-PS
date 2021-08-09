package simulation;
/*
    [BOJ] 14503 로봇 청소기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14503 {
    static int N, M;

    static int dy[] = {-1, 0, 1, 0}; // 북 동 남 서
    static int dx[] = {0, 1, 0, -1};
    static int[][] map;

    static int stoi(String token) {
        return Integer.parseInt(token);
    }

    static int changeDir(int dir) {
        if (dir == 0) {
            return 3;
        } else if (dir == 1) {
            return 0;
        } else if (dir == 2) {
            return 1;
        } else if (dir == 3) {
            return 2;
        }
        return 0;
    }
    static int numOfClean(){
        int cnt= 0 ;
        for(int i =0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(map[i][j] == 2){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int y, x, d;
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());

        st = new StringTokenizer(br.readLine());

        y = stoi(st.nextToken());
        x = stoi(st.nextToken());
        d = stoi(st.nextToken());

        map = new int[N + 1][M + 1];
        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; ++j) {
                map[i][j] = stoi(st.nextToken());
            }
        }
        while (true) {
            map[y][x] = 2;
            int nd = d;

            int cnt = 0;
            boolean flag = false;

            while (cnt <= 3) {

                nd = changeDir(nd);
                int ny = y + dy[nd];
                int nx = x + dx[nd];
                if(ny<0 || nx<0 || ny>=N || nx>=M) {
                    d  = nd;
                    break;
                }
                if (map[ny][nx] == 0) {
                    map[ny][nx] = 2;
                    y = ny;
                    x = nx;
                    d = nd;
                    break;
                }
                cnt++;
            }
            if (cnt==4) {
                //청소할 공간이 없으면 바라보는 방향으로 한칸 후진
                int ny = y - dy[d];
                int nx = x - dx[d];
                if (map[ny][nx] == 1) {
                    break;
                }
                y = ny;
                x = nx;
            }
        }
        System.out.println(numOfClean());
    }
}
