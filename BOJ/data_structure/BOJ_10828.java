package DataStructure;

import java.io.*;
import java.util.Stack;

public class BOJ_10828 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
        Stack<Integer> s = new Stack<>();
        int n=0;
        n = Integer.parseInt(br.readLine());

        for(int i=0; i<n; ++i) {
            String[] cmd = br.readLine().split(" ");

            switch(cmd[0]){
                case "push":
                    s.push(Integer.parseInt(cmd[1]));
                    break;
                case "pop":
                    if(s.empty()){
                        bw.write("-1\n");
                    }else{
                        bw.write(s.pop()+"\n");
                    }
                    break;
                case "size":
                    bw.write(s.size()+"\n");
                    break;
                case "empty":
                    if(s.empty()){      //비어있으면
                        bw.write("1\n");
                    }else{
                        bw.write("0\n");
                    }
                    break;
                case "top":
                    if(s.empty()){
                        bw.write("-1\n");
                    }else {
                        bw.write(s.peek() + "\n");
                    }
                    break;
            }
        }
        bw.flush();
        bw.close();
    }
}
