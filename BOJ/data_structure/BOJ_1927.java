package DataStructure;
/*
    [BOJ] 1927 최소 힙
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.PriorityQueue;
public class BOJ_1927 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());

        while((N--) != 0){
            int x = Integer.parseInt(br.readLine());
            if(x == 0){
                if(pq.isEmpty()){
                   System.out.println(0);
                }else{
                    System.out.println(pq.poll());
                }
            }else{
                pq.add(x);
            }

        }
    }
}
