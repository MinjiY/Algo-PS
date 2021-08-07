package BFS;
/*
    [BOJ] 7569 토마토
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_7569 {
    static int N,M,H;
    static int dy[] = new int[]{0,0,0,0,-1,1};
    static int dx[] = new int[]{0,0,-1,1,0,0};
    static int dz[] = new int[]{-1,1,0,0,0,0};

    static int map[][][];
    static int visit[][][];
    static Queue<NODE> q = new ArrayDeque<>();
    static void bfs(){

        while(!q.isEmpty()){
            NODE node = q.poll();

            for(int i=0;i<6; ++i){
                int nz = node.z + dz[i];
                int ny = node.y + dy[i];
                int nx = node.x + dx[i];
                if(ny<0 || nx<0 || nz<0 || ny>=N || nx>=M || nz>=H) continue;
                if(visit[nz][ny][nx] == 0 && map[nz][ny][nx] != (-1)){
                    visit[nz][ny][nx] = 1;
                    map[nz][ny][nx] = map[node.z][node.y][node.x]+1;
                    q.add(new NODE(nz,ny,nx));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M= Integer.parseInt(st.nextToken());
        N= Integer.parseInt(st.nextToken());
        H= Integer.parseInt(st.nextToken());

        map= new int[H+1][N+1][M+1];
        visit= new int[H+1][N+1][M+1];

        for(int k=0; k<H; ++k){
            for(int i=0; i<N; ++i){
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                for(int j=0; j<M; ++j){
                    map[k][i][j] = Integer.parseInt(st2.nextToken());
                    if(map[k][i][j] == 1){
                        q.add(new NODE(k,i,j));
                        visit[k][i][j] = 1;
                    }
                }
            }
        }

        bfs();
        boolean flag = true;
        int ans = 0;
        for(int k=0; k<H; ++k){
            for(int i=0; i<N; ++i){
                for(int j=0; j<M; ++j){
                    if(map[k][i][j] == 0){
                        flag = false;
                        break;
                    }
                    if(map[k][i][j] > ans){
                        ans = map[k][i][j];
                    }
                }
            }
        }

        if(flag){
           System.out.println(ans-1);
        }else{
            System.out.println(-1);
        }

    }
    static class NODE{
        int z;
        int y;
        int x;
        NODE(int z, int y,  int x){
            this.z = z;
            this.y= y;
            this.x = x;
        }
    }
}
