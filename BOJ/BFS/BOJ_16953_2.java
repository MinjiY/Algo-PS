package BFS;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_16953_2 {
    static long A;
    static long B;
    static int ans;

    static void bfs() {
        Queue<NODE> q = new LinkedList<>();
        q.add(new NODE(A, 0));

        while (!q.isEmpty()) {
            NODE temp = q.poll();
            long curNode = temp.node;
            int cnt = temp.cnt;

            if (curNode == B) {
                //찾음
                ans = cnt;
                return;
            } else if (curNode > B) {
                continue;
            } else {
                q.add(new NODE(curNode * 2, cnt + 1));
                long tempNode = (curNode * 10) + 1;
                q.add(new NODE(tempNode, cnt + 1));
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());


        bfs();
        if (ans == 0) {
            System.out.println("-1");
        } else {
            System.out.println(ans + 1);
        }
    }

    static class NODE {
        long node;
        int cnt;

        NODE(long node, int cnt) {
            this.node = node;
            this.cnt = cnt;
        }
    }
}


