package DataStructure;

import java.io.*;
import java.util.Stack;


public class BOJ_1406 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        int n = Integer.parseInt(br.readLine());
        Stack<String> leftStack = new Stack<>();
        Stack<String> rightStack = new Stack<>();
        String[] temp = s.split("");
        for(int i=0; i<temp.length; ++i){
            leftStack.push(temp[i]);
        }
        while((n--) != 0){
            String[] ord = br.readLine().split(" ");
            if(ord[0].equals("L")){
                if(!leftStack.empty()) {
                    rightStack.push(leftStack.pop());
                }
            }else if(ord[0].equals("D")){
                if(!rightStack.empty()){
                    leftStack.push(rightStack.pop());
                }
            }else if( ord[0].equals("B")){
                if(!leftStack.empty()){
                    leftStack.pop();
                }
            }else if(ord[0].equals("P")){
                leftStack.push(ord[1]);
            }
        }

        while(!leftStack.empty()){
            rightStack.push(leftStack.pop());
        }
        while(!rightStack.empty()){
            bw.write(rightStack.pop());
        }

        bw.flush();
        bw.close();
    }
}
