package DataStructure;

import java.util.Deque;
import java.util.ArrayDeque;
import java.io.*;

public class BOJ_10866 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n =0 ;
        n = Integer.parseInt(br.readLine());

        Deque<Integer> dq = new ArrayDeque<Integer>();
        for(int i=0; i<n; ++i){
            String[] cmd = br.readLine().split(" ");
            switch(cmd[0]) {
                case "push_front":
                    dq.addFirst(Integer.parseInt(cmd[1]));
                    break;
                case "push_back":
                    dq.addLast(Integer.parseInt(cmd[1]));
                    break;
                case "pop_front":
                    if (dq.isEmpty()) bw.write("-1\n");
                    else bw.write(String.valueOf(dq.pollFirst()) + "\n");
                    break;
                case "pop_back":
                    if (dq.isEmpty()) bw.write("-1\n");
                    else bw.write(dq.pollLast() + "\n");
                    break;
                case "size":
                    bw.write(dq.size() + "\n");
                    break;
                case "empty":
                    if (dq.isEmpty()) bw.write("1\n");
                    else bw.write("0\n");
                    break;
                case "front":
                    if (dq.isEmpty()) bw.write("-1\n");
                    else bw.write(dq.peekFirst() + "\n");
                    break;
                case "back":
                    if (dq.isEmpty()) bw.write("-1\n");
                    else bw.write(dq.peekLast() + "\n");
                    break;
            }
        }
        bw.flush();
        bw.close();
    }
}
