package programmers.kakao_kakaoCodeFinal2017;

import java.util.HashMap;

// A C F J M N R T
public class 단체사진찍기 {
    static char[] arr = new char[8];
    static char[] selected = new char[8];
    static int[] visit = new int[8];
    static int ans;
    static String[] args;
    static public boolean check(){
        // selected에 0~7까지의 순열이 저장되어있음
        for(String in: args) {
            int[] al = new int[2];
            int indx = 0;
            for (int i = 0; i < 8; ++i) {
                if((selected[i] == in.charAt(0)) || selected[i] == in.charAt(2) ) {
                    al[indx] = i;
                    indx++;
                }
            }
            //인덱스끼리의 diff
            int diff = Math.abs(al[0] - al[1]);
            int res = in.charAt(4)-'0'+1;
            if(in.charAt(3) == '='){
                if(diff != res){
                    return false;
                }
            }else if(in.charAt(3) == '>'){
                if(!(diff > res)){
                    return false;
                }
            }else if(in.charAt(3) == '<')
            {
                if(!(diff < res)){
                    return false;
                }
            }
        }
//        System.out.println();
        return true;
    }
    static void permutation( int cnt){
        if(cnt == 8){
            if(check()){
                ans++;
            }
            return;
        }
        for(int i=0; i<8; ++i){
            if(visit[i] == 0){
                visit[i] = 1;
                selected[cnt] = arr[i];
                permutation(cnt+1);
                visit[i] = 0;
            }
        }

    }
    static public int solution(int n, String[] data) {
        int answer = 0;

        arr[0] = 'A';
        arr[1] = 'C';
        arr[2] = 'F';
        arr[3] = 'J';
        arr[4] = 'M';
        arr[5] = 'N';
        arr[6] = 'R';
        arr[7] = 'T';

        args = data;
        ans=0;
        permutation(0);
        System.out.println(ans);


        return answer;
    }
    public static void main(String[] args){
        String[] data1 = {"N~F=0", "R~T>2"};
        String[] data2 = {"M~C<2", "C~M>1"};
        int n = 2;

        solution(n,data1);
    }
}
