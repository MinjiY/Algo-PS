package BFS;
/*
    [BOJ] 16946 벽 부수고 이동하기 4
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_16946 {
    static int[][] map;
    static int[][] visit;
    static int[][] zero;
    static int[][] numbering;

    static int[] dy = {0,0,-1,1};
    static int[] dx = {1,-1,0,0};

    static int N, M;

    static ArrayList<Point> arrayList = new ArrayList<>();

    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static int bfs(int y, int x, int number){
        int zeroCnt= 1;
        Queue<Point> q = new ArrayDeque<>();
        q.add(new Point(y,x));
        visit[y][x] =1;
        numbering[y][x] = number;
        arrayList.add(new Point(y,x));


        while(!q.isEmpty()){
            Point node = q.poll();

            for(int i=0; i<4; ++i){
                int ny = node.y +dy[i];
                int nx = node.x +dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;

                if(visit[ny][nx] == 0 && map[ny][nx] ==0){
                    visit[ny][nx] = 1;
                    zeroCnt++;
                    numbering[ny][nx] = number;
                    arrayList.add(new Point(ny,nx));
                    q.add(new Point(ny,nx));
                }
            }
        }
        return zeroCnt;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = stoi(st.nextToken());
        M = stoi(st.nextToken());

        map = new int[N][M];
        visit = new int[N][M];
        zero = new int[N][M];
        numbering = new int[N][M];

        for(int i=0; i<N; ++i){
            String temp = br.readLine();
            for(int j=0; j<M; ++j){
                map[i][j] = temp.charAt(j)-'0';
            }
        }


        int number = 1;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j) {

                if(map[i][j] == 0 && visit[i][j] ==0) {
                    int zeroCnt = bfs(i,j,number);

                    for(int k=0; k<arrayList.size(); ++k){
                        Point point = arrayList.get(k);
                        zero[point.y][point.x] = zeroCnt;
                    }
                    number++;
                    arrayList.clear();
                }
            }
        }
//        printZero();
//        printNumbering();
        for(int i = 0; i < visit.length; i++) {
            Arrays.fill(visit[i], 0);
        }

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(map[i][j] == 1){
                    HashSet<Integer> hs = new HashSet<>();
                    int sum = 1;
                    for(int k=0; k<4; ++k){
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(ny<0 || nx<0 || ny>= N || nx>=M) continue;

                        if(map[ny][nx] == 0 && (hs.contains(numbering[ny][nx]) == false)){
                            sum += zero[ny][nx];
                            hs.add(numbering[ny][nx]);
                        }
                    }
                    visit[i][j] = (sum%10);
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                sb.append(visit[i][j]);
            }
            sb.append("\n");
        }

        System.out.println(sb);
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
