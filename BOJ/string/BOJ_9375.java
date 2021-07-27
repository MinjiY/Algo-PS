package string;
/*
    [BOJ] 9375 패션왕 신해빈
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class BOJ_9375 {
    static int getCase(HashMap<String,Integer> hm){
        int ans = 1;
        for(String key : hm.keySet()){
            ans *= (hm.get(key)+1);
        }
        return ans-1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while((T--) != 0){
            int N = Integer.parseInt(br.readLine());
            HashMap<String,Integer> hm = new HashMap<>();
            for(int i=0; i<N; ++i){

                StringTokenizer st = new StringTokenizer(br.readLine());
                String v = st.nextToken();
                String k = st.nextToken();
                int cnt = hm.getOrDefault(k,0);
                hm.put(k,cnt+1);
            }
            System.out.println(getCase(hm));
        }
    }
}
