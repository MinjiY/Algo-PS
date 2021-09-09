package BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class BOJ_1920 {
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static long stol(String token){
        return Long.parseLong(token);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        TreeSet<Long> set = new TreeSet<>();
        int N, M;
        N = stoi(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i){
            set.add(stol(st.nextToken()));
        }
        M = stoi(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<M; ++i){
            if(set.contains(stol(st.nextToken()))==true){
                sb.append("1\n");
            }else{
                sb.append("0\n");
            }
        }
        System.out.print(sb);
    }
}
