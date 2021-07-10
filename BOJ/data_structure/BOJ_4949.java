package DataStructure;

import java.io.*;
import java.util.Stack;

public class BOJ_4949 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        while(true){
            Stack<Character> stack = new Stack<>();
            String in = br.readLine();
            boolean flag = true;
            if(in.equals(".")){
                break;
            }
            for(int i=0; i<in.length(); ++i){
                char c = in.charAt(i);
                if( c == '(' || c=='['){
                    stack.push(c);
                }else if(c == ')' ){
                    if(!stack.empty() && stack.peek() == '('){
                        stack.pop();
                    }else{
                        flag = false;
                        break;
                    }
                }else if( c == ']'){
                    if(!stack.empty() &&  stack.peek() == '['){
                        stack.pop();
                    }else{
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                if(stack.empty()) {
                    bw.write("yes\n");
                }else {
                    bw.write("no\n");
                }
            }else{
                bw.write("no\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
