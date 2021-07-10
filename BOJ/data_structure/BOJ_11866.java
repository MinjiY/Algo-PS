package DataStructure;

import java.util.Queue;
import java.util.LinkedList;
import java.io.*;

public class BOJ_11866 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n=0, k=0;

        Queue<Integer> q = new LinkedList<>();
        LinkedList<Integer> ll = new LinkedList<>();
        String[] cmd = br.readLine().split(" ");
        n = Integer.parseInt(cmd[0]);
        k = Integer.parseInt(cmd[1]);

        int cnt = 1;


        for(int i=1; i<=n; ++i){
            q.add(i);
        }
        bw.write("<");
        while(!q.isEmpty()){
            int temp = q.poll();
            //bw.write(temp);
            if(cnt%k != 0){
                q.add(temp);
            }else{
                bw.write(String.valueOf(temp));
                if(q.size()!=0) {
                    bw.write(", ");
                }
            }
            cnt++;
        }
        bw.write(">");
        bw.flush();
        bw.close();

    }
}
