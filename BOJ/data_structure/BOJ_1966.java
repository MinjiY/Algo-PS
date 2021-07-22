package DataStructure;
/*
    [BOJ] 1966 프린터 큐
 */

import java.io.*;
import java.util.*;

public class BOJ_1966 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        LinkedList<Integer> ll = new LinkedList<>();
        LinkedList<NODE> queue = new LinkedList<NODE>();
        int T = Integer.parseInt(br.readLine());
        while ((T--) != 0) {
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st1.nextToken());
            int M = Integer.parseInt(st1.nextToken());
            int num = 0;
            NODE find_num = new NODE();
            while (st2.hasMoreTokens()) {
                int temp = Integer.parseInt(st2.nextToken());
                if (num == M) {
                    find_num.value = temp;
                    find_num.indx = num;
                }
                NODE node = new NODE(temp, num);
                queue.add(node);
                ll.add(temp);
                num++;
            }
            Collections.sort(ll, Collections.reverseOrder());
            num = 1;
            for (int i = 0; i < ll.size(); ++i) {
                boolean flag = false;
                while(true){
                    if(ll.get(i) == queue.peek().value){
                        if(find_num.indx == queue.peek().indx){
                            bw.write(String.valueOf(num)+"\n");
                            //System.out.println(num);
                            flag = true;
                            break;
                        }else{
                            queue.poll();
                        }
                        num++;
                        break;
                    }
                    NODE temp = queue.poll();
                    queue.add(temp);
                    ll.add(ll.get(i));
                }
                if(flag){
                    break;
                }
            }
            queue.clear();
            ll.clear();
        }
        bw.flush();
        bw.close();
    }
    static void sort(LinkedList<NODE> queue){
        Collections.sort(queue, new Comparator<NODE>() {
            @Override
            public int compare(NODE o1, NODE o2){
                return o2.value - o1.value;
            }
        });
    }

    static class NODE {
        int value;
        int indx;

        NODE() {
        }

        public NODE(int value, int indx) {
            this.value = value;
            this.indx = indx;
        }
    }
}

