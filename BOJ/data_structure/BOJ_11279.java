package DataStructure;
/*
    [BOJ] 11279 최대 힙
 */

import java.io.*;
import java.util.Collections;
import java.util.PriorityQueue;

public class BOJ_11279 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int N = Integer.parseInt(br.readLine());

        while((N--)!=0){
            int x = Integer.parseInt(br.readLine());
            if( x == 0){
                if(pq.isEmpty()){
                    bw.write("0\n");
                    //System.out.println(0);
                }else{
                    bw.write(String.valueOf(pq.poll())+"\n");
                    //System.out.println(pq.poll());
                }
            }else{
                pq.add(x);
            }
        }
        bw.flush();
        bw.close();
    }
}
