package programmers.kakao_BlindRecruitment2018;
/*
    [Programmers] 2018 Kakao Blind Recruitment 프렌즈4블록
 */
import java.util.Arrays;

public class 프렌즈4블록 {
    static int N;
    static int M;
    static char[][] map;
    static int[][] visit;

    static boolean find4Friends(){
        //4개씩 탐색
        boolean flag = false;

        for(int i=0; i<N-1; ++i){
            for(int j=0; j<M-1; ++j){
                if(map[i][j] == map[i+1][j] && map[i][j] == map[i][j+1] && map[i][j] == map[i+1][j+1] && map[i][j] != 'r'){
                    visit[i][j] = visit[i+1][j] = visit[i][j+1] = visit[i+1][j+1] = 1;
                    flag= true;
                }
            }
        }
        return flag;
    }
    static void remove4Friends() {
        // visit 표시한대로 Friends 삭제
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visit[i][j] == 1) {
                    map[i][j] = 'r';
                }
            }
        }

        // 빈칸 채우기
        for(int j=0; j<M; ++j){
            for(int i=N-1; i>=0; --i){
                if(map[i][j] == 'r') {
                    int swapCnt = 0 ;
                    for (int k = i - 2; k >= 0; --k) {
                        if (map[k][j] != 'r') {
                            map[i - (swapCnt++)][j] = map[k][j];
                            map[k][j] = 'r';
                        }
                    }
                }
            }
        }
    }
    static void fillZero(){
        for (int i = 0; i < N; ++i) {
            Arrays.fill(visit[i],0);
        }
    }
    static int countingFriends(){
        int cnt = 0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(map[i][j] =='r'){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    static public int solution(int m, int n, String[] board) {
        int answer = 0;
        N = m;
        M = n;
        map = new char[N][M];
        visit= new int[N][M];

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                map[i][j] = board[i].charAt(j);
            }
        }
        while(find4Friends()){
            remove4Friends();
            fillZero();
        }
        answer = countingFriends();
        return answer;
    }

    public static void main(String[] args){
        String[] board = {"CCBDE","AAADE","AAABF","CCBBF"};
        int m = 4;
        int n = 5;
//        String[] board= {"TTTANT","RRFACC","RRRFCC","TRRRAA","TTMMMF","TMMTTJ"};
//        int m = 6;
//        int n = 6;
        System.out.println(solution(m,n,board));
    }
}
