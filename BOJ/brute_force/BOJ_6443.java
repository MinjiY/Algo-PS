package brute_force;

import java.io.*;
public class BOJ_6443 {
    static int n;
    static int[] visit;
    static char[] selected = new char[20];
    static int cur_length;
    static char[] cArr;
 //   static BufferedWriter bw;
    static StringBuilder sb = new StringBuilder();              //25604KB 348ms
    static void permutation(int cnt) throws IOException{
        if(cnt == cur_length){
            for(int i=0; i<cnt; ++i){
                sb.append(selected[i]);
            //    bw.write(String.valueOf(selected[i]));
            }
            //bw.write("\n");
            sb.append("\n");
            return;
        }
        for(int i=0; i<26; ++i){
            if(visit[i]>0 ){
                visit[i]--;
                selected[cnt] = (char)('a'+i);
                permutation(cnt+1);
                visit[i]++;
            }
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
//        bw = new BufferedWriter(new OutputStreamWriter(System.out));  82840KB 428ms

        for(int i=0; i<n; ++i){
            visit = new int[26];
            cArr = br.readLine().toCharArray();
            cur_length = cArr.length;
            for(int j=0; j<cur_length ;++j){
                visit[cArr[j]-'a']++;
            }
            permutation(0);
            System.out.print(sb);
            sb.setLength(0);
        }

 //       bw.flush();
//        bw.close();
    }
}
