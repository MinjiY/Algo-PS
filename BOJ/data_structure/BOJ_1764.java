package DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1764 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int ans = 0;
        Map<String,Integer> m = new TreeMap<>();

        for(int i=0; i<N; ++i){
            String in =br.readLine();
            m.put(in,1);
        }
        for(int i=0; i<M; ++i){
            String in = br.readLine();
            int cnt= m.getOrDefault( in,0);
            cnt++;
            m.put(in,cnt);
        }

        for(String key: m.keySet()){
           if(m.get(key) == 2){
               sb.append(key+"\n");
               ans++;
           }
        }
        System.out.println(ans);
        System.out.println(sb);
    }
}
