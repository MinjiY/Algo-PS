package programmers.codeChallange;

/*
    [Programmers] 월간 코드 챌린지 시즌3 > 빛의 경로 사이클
    https://programmers.co.kr/learn/courses/30/lessons/86052
 */
/*
    빛이 S 가 써진 칸에 도달한 경우, 직진한다.
    빛이 L 이 써진 칸에 도달한 경우, 좌회전
    빛이 R 이 써진 칸에 도달한 경우, 우회전
    빛이 격자의 끝을 넘어갈 경우, 반대쪽 끝으로 다시 돌아온다.
    격자 내에서 빛이 이동할 수 있는 경로 사이클이 몇 개 있고, 이 사이클의 길이를 알고싶음

    1 <= grid <= 500
    1 <= grid.length() <= 500
 */
import java.util.ArrayList;
import java.util.Arrays;

public class 빛의경로사이클 {
    static int N;
    static int M;
    static char[][] map;
    static int[][][] visit;
    // 아래0 왼1 위2 오른3
    static int[] dy = {-1,0,1,0};
    static int[] dx = {0,-1,0,1};

    static int move(int y, int x, int cur){
        int cur_y = y;
        int cur_x = x;
        int dir = cur;
        int cnt = 0;

        while(true){
            if(visit[cur_y][cur_x][dir] == 1){
                break;
            }
            visit[cur_y][cur_x][dir] = 1;
            cnt++;

            if(map[cur_y][cur_x] == 'L'){
                dir = dir == 0 ? 3 : dir -1;
            }
            else if(map[cur_y][cur_x] == 'R'){
                dir = dir == 3 ? 0 : dir+1;
            }
            cur_y = (cur_y + dy[dir]+ N) % N;
            cur_x = (cur_x + dx[dir]+ M) % M;
        }
        return cnt;
    }
    static public int[] solution(String[] grid) {
        ArrayList<Integer> answer  = new ArrayList<>();

        N = grid.length;
        M = grid[0].length();
        map = new char[N][M];
        visit = new int[N][M][4];

        //char 격자로 변경
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                map[i][j] = grid[i].charAt(j);
            }
        }

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                for(int k=0; k<4; ++k){
                    if(visit[i][j][k] == 0){
                        answer.add(move(i,j,k));
                    }
                }
            }
        }
        return answer.stream().sorted().mapToInt(i->i).toArray();
    }
    public static void main(String[] args){
        String[] grid = { "R","R"};
        System.out.println(solution(grid));
    }
}
