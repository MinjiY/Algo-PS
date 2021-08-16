package DataStructure;
/*
    [BOJ] 2841 외계인의 기타 연주
    `
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ_2841 {
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N, P;
        int cnt =0 ;
        N = stoi(st.nextToken());
        P = stoi(st.nextToken());

        Stack<Integer> stack[] = new Stack[7];
        for(int i=0; i<7; ++i){
            stack[i] = new Stack<Integer>();
        }
        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            int indx = stoi(st.nextToken());
            int flat = stoi(st.nextToken());

            if(stack[indx].empty()){
                stack[indx].push(flat);
                cnt++;
            }else{
                if(!stack[indx].empty() && (stack[indx].peek() < flat)){
                    stack[indx].push(flat);
                    cnt++;
                }else{
                    // 지금 누르려는 플랫보다 큰거 일단 다빼
                    while(!stack[indx].empty() && (stack[indx].peek() > flat)){
                        stack[indx].pop();
                        cnt++;
                    }
                    // 다 빠졌으면? 누르려는 플랫이 스택 상위에 있는거보다 작거나 같은거자나
                    //
//                    if(!stack[indx].empty()&& (stack[indx].peek() == flat) ){
//                        //같은거는 카운트 안돼
//
//                    }else if(!stack[indx].empty()&& (stack[indx].peek() != flat)){
//                        stack[indx].push(flat);
//                        cnt++;
//                    }else {
//                        //스택이 비어있어
//                        stack[indx].push(flat);
//                        cnt++;
//                    }
                    if(!stack[indx].empty()&& (stack[indx].peek() != flat)){
                        stack[indx].push(flat);
                        cnt++;
                    }else if(stack[indx].empty()){
                        //스택이 비어있어
                        stack[indx].push(flat);
                        cnt++;
                    }
                }
            }
        }
        System.out.println(cnt);
    }
}
