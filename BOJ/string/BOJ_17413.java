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
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();
        Stack<Character> stack = new Stack<Character>();
        // true: 괄호
        boolean flag = false;
        for (int i = 0; i < str.length(); ++i) {
            char c = str.charAt(i);
            if (c == '<') {
                while (!stack.empty()) {
                    System.out.print(stack.pop());
                }
                System.out.print(c);
                flag = true;
            } else if (c == '>') {
                System.out.print(c);
                flag = false;
            } else if (flag == true) {
                System.out.print(c);
            } else {

                if (c == ' ') {
                    while (!stack.empty()) {
                        System.out.print(stack.pop());
                    }
                    System.out.print(c);
                } else {
                    stack.push(c);
                }

            }
        }
        while (!stack.empty()) {
            System.out.print(stack.pop());
        }
    }
}
