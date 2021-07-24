package string;
/*
    [BOJ] 3005 크로스워드 퍼즐 쳐다보기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_3005 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        char[][] puzzle = new char[R + 1][C + 1];
        String[] words = new String[(R + 1) * (C + 1)];
        int words_indx = 0;
        String ans = "";

        //토크나이저로 받은거 puzzle로
        for (int i = 0; i < R; ++i) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            String str = st2.nextToken();
            for (int j = 0; j < C; ++j) {
                puzzle[i][j] = str.charAt(j);
            }
        }

        //왼쪽에서 오른쪽으로 단어찾기
        for (int i = 0; i < R; ++i) {
            String temp = "";
            for (int j = 0; j < C; ++j) {
                if (puzzle[i][j] == '#') {
                    if (temp.length() >= 2) {
                        words[words_indx++] = temp;
                    }
                    temp="";
                }else {
                    temp += puzzle[i][j];
                }
            }
            if (temp.length() >= 2) {
                words[words_indx++] = temp;
            }
        }

        //위에서 아래로 단어찾기
        for (int j = 0; j < C; ++j) {
            String temp = "";
            for (int i = 0; i < R; ++i) {
                if (puzzle[i][j] == '#') {
                    if (temp.length() >= 2) {
                        words[words_indx++] = temp;
                    }
                    temp = "";
                } else {
                    temp += puzzle[i][j];
                }
            }
            if (temp.length() >= 2) {
                words[words_indx++] = temp;
            }
        }


        // 사전순으로 비교해서 가장 앞에있는애 찾기
        ans = words[0];
        for (int i = 1; i < words_indx; ++i) {
            if (ans.compareTo(words[i]) >= 1)    //words[i-1]이 사전순으로 더 앞에 있다
            {
                ans = words[i];
            }
        }
        System.out.println(ans);

    }
}
