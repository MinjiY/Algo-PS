package string;
/*
    [BOJ] 17413 단어 뒤집기2
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BOJ_17413 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        Stack<Character> stack = new Stack<Character>();
        // true: 괄호
        boolean flag = true;
        for(int i=0; i<str.length(); ++i){
            char c = str.charAt(i);
            if(c == '<'){
                while(!stack.empty()){
                    System.out.print(stack.pop());
                }
                System.out.print(c);
                flag = true;
            }else if(c == '>'){
                System.out.print(c);
                flag = false;
            }else {
                if(flag == false){
                    stack.push(c);
                }else{
                    System.out.print(c);
                }
            }
        }
    }
}
