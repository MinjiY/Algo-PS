package BFS;
/*
    [BOJ] 4963 섬의 개수
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_4963 {
    static int M, N;
    static int[][] map;
    static boolean[][] visit;
    static int dy[] = {0,0,-1,1,-1,-1,1,1};
    static int dx[] = {-1,1,0,0,1,-1,1,-1};
    static void printMap(){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
    }
    static void bfs(int y, int x){
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(y,x));
        visit[y][x] =true;

        while(!q.isEmpty()){
            Pair node = q.poll();

            for(int i=0; i<8; ++i){
                int ny = node.y+dy[i];
                int nx = node.x+dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(visit[ny][nx] == false && map[ny][nx] == 1){
                    visit[ny][nx] = true;
                    q.add(new Pair(ny,nx));
                }

            }
        }


    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            int island = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            if( M == 0 && N ==0){
                break;
            }
            map = new int[N+1][M+1];
            visit = new boolean[N+1][M+1];

            for(int i=0; i<N; ++i){
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                for(int j=0; j<M; ++j){
                    map[i][j] = Integer.parseInt(st2.nextToken());
                }
            }

            for(int i=0; i<N; ++i){
                for(int j=0; j<M; ++j){
                    if(visit[i][j] == false&& map[i][j] == 1){
                        island++;
                        bfs(i,j);
                    }
                }
            }
            System.out.println(island);

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
