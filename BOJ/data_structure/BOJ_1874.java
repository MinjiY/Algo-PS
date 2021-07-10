package DataStructure;

import java.util.Stack;
import java.io.*;
import java.util.ArrayList;

public class BOJ_1874 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter((System.out)));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Character> arrList = new ArrayList<>();
        Stack<Integer> s = new Stack<>();
        boolean flag = true;
        int num = 1;
        for (int i = 0; i < n; ++i) {

            int m = Integer.parseInt(br.readLine());


            if (num > m) {              //현재 넘버가 입력 넘버보다 커 => 충분히 증가시킨 경우
                //계속 뺌
                if(s.empty()){          // 비어있으면 못뺌 => 못찾음
                    flag = false;
                    break;
                }
                while(s.peek() != m){
                    s.pop();
                    arrList.add('-');
                    if(s.empty()){      // 아직 못찾았는데 비어버림  => 못찾음
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
                s.pop();
                arrList.add('-');
            }
            //현재 넘버가 입력 넘버보다 작거나 같으면? push
            else if (num <= m) {
                // 계속 push

                while(true){
                    if(s.empty() == false && s.peek() == m){    //안 비었고 찾음
                        break;
                    }
                    s.push(num);
                    num++;
                    arrList.add('+');
                }
                s.pop();
                arrList.add('-');
            }

        }
        if (flag)
        {
            for(int i=0; i<arrList.size(); ++i){
                bw.write(arrList.get(i)+"\n");
            }
        }else{
            bw.write("NO\n");
        }
        bw.flush();
        bw.close();
    }
}
