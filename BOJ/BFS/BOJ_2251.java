package BFS;
/*
    [BOJ] 2251 물통
 */
import java.io.*;
import java.util.*;

public class BOJ_2251 {
    static int A, B, C;
    static ArrayList<Integer> ans = new ArrayList<>();
    static boolean[][][] visit = new boolean[201][201][201];

    static void bfs() {
        Queue<NODE> q = new LinkedList<>();
        q.add(new NODE(0, 0, C));

        while (!q.isEmpty()) {
            NODE node = q.poll();
            // System.out.println(node.A + " "+node.B+" "+node.C);

            if (visit[node.A][node.B][node.C] == true) {
                continue;
            }
            visit[node.A][node.B][node.C] = true;

            if (node.A == 0) {
                ans.add(node.C);
            }
            // C에서 A나 B로
            //A에 들어있는거 + C에 들어있는거 <= A의 용량
            q.add(new NODE(Math.min(node.A + node.C, A), node.B, Math.max(node.C - (A - node.A), 0)));
            //B에 들어있는거 + C에 들어있는거 <= B의 용량
            q.add(new NODE(node.A, Math.min(node.B + node.C, B), Math.max(node.C - (B - node.B), 0)));

            // B에서 A나 C로
            // A
            q.add(new NODE(Math.min(node.A + node.B, A), Math.max(node.B - (A - node.A), 0), node.C));
            //C
            q.add(new NODE(node.A, Math.max(node.B - (C - node.C), 0), Math.min(node.C + node.B, C)));

            // A에서 B나 C로
            //B
            q.add(new NODE(Math.max(node.A - (B - node.B), 0), Math.min(node.B + node.A, B), node.C));
            //C
            q.add(new NODE(Math.max(node.A - (C - node.C), 0), node.B, Math.min(node.C + node.A, C)));
        }


    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        bfs();
        Collections.sort(ans);
        for (int i = 0; i < ans.size(); ++i) {
            bw.write(String.valueOf(ans.get(i))+" ");
            //System.out.print(ans.get(i) + " ");
        }
        bw.flush();
        bw.close();
    }

    static class NODE {
        int A;
        int B;
        int C;

        NODE(int A, int B, int C) {
            this.A = A;
            this.B = B;
            this.C = C;
        }
    }
}
