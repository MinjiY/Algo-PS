package string;
/*
    [BOJ] 4889 안정적인 문자열
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BOJ_4889 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Character> stack = new Stack<Character>();
        int num = 1;
        while(true){
            String str = br.readLine();
            int cnt = 0;

            if(str.charAt(0) == '-') {
                break;
            }
            for(int i=0; i<str.length(); ++i){
                if(str.charAt(i) == '}'){
                    if(!stack.empty() && stack.peek() == '{'){
                        stack.pop();
                        continue;
                    }
                }
                stack.push(str.charAt(i));
            }

            while(!stack.empty()){
                char c = stack.pop();
                if( c == '{'){
                    cnt++;
                    if(!stack.empty() && stack.peek() == '{') {
                        stack.pop();
                    }
                }
                else if (c =='}'){
                    cnt++;
                    if(!stack.empty() && stack.peek() == '}') {
                        stack.pop();
                    }
                }
            }

            System.out.println(num+". "+cnt);
            num++;
        }

    }
}
