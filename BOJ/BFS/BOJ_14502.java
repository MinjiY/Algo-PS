package BFS;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;
import java.io.IOException;

public class BOJ_14502 {
    static int[][] map;
    static int[][] visit;
    static int[] dy = {0,0,-1,1};
    static int[] dx = {1,-1,0,0};
    static ArrayList<Point> arrList = new ArrayList<>();
    static int N, M, ans;

    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void printMap(){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
    static void bfs(){

        Queue<Point> q = new ArrayDeque<>();
        for(int i=0; i<arrList.size(); ++i){
            q.add(new Point(arrList.get(i).y, arrList.get(i).x));
            visit[arrList.get(i).y][arrList.get(i).x] = 1;
        }
        while(!q.isEmpty()){
            Point point = q.poll();

            for(int i=0; i<4; ++i){
                int ny = point.y +dy[i];
                int nx = point.x +dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;

                if(visit[ny][nx] == 0 && map[ny][nx] == 0){
                    visit[ny][nx] = 1;
                    q.add(new Point(ny,nx));
                }
            }
        }
    }
    static void combination(int indx, int cnt){
        if(cnt == 3){
            for(int i=0; i<visit.length; ++i){
                Arrays.fill(visit[i],0);
            }
            bfs();
            int safe = 0;
            for(int i=0; i<N; ++i){
                for(int j=0; j<M; ++j){
                    if(map[i][j] == 0 && visit[i][j] == 0){
                        safe++;
                    }
                }
            }
            if(ans < safe){
                ans = safe;
            }
            return;
        }

        for(int i=0; i<N; ++i){
            for(int j=indx; j<M; ++j){
                if(map[i][j] == 0){
                    map[i][j] = 1;
                    combination(j,cnt+1);
                    map[i][j] =0;
                }
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());

        map = new int[N][M];
        visit = new int[N][M];


        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<M; ++j){
                int temp = stoi(st.nextToken());
                map[i][j] = temp;
                if(temp == 2){
                    arrList.add(new Point(i,j));
                }
            }
        }
        combination(0,0);
        System.out.println(ans);

    }
    static class Point{
        int y;
        int x;
        Point(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
