package graph;
/*
    [BOJ] 5567 결혼식
    상근이 친구의 친구만 초대 => 초대할 수 있는 인원 출력
    상근이 1번
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_5567 {
    static ArrayList<Integer> friendList[];
    static boolean visit[];
    static int N;
    static int ans;
    static class NODE{
        int node;
        int cnt;
        NODE(int node, int cnt){
            this.node = node;
            this.cnt = cnt;
        }
    }
    static void bfs(){
        int depth = 2;
        Queue<NODE> queue = new LinkedList<>();
        queue.add(new NODE(1,0));
        visit[1] = true;
        while(!queue.isEmpty()){
            NODE temp = queue.poll();
            int node = temp.node;
            int cnt = temp.cnt;
            if(cnt <= depth){
                ans++;
            }else{
                continue;
            }
            for(int i=0; i<friendList[node].size(); ++i){
                int next = friendList[node].get(i);
                if(visit[next] == false){
                    visit[next] = true;
                    queue.add(new NODE(next,cnt+1));
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        friendList = new ArrayList[N+1];
        visit = new boolean[N+1];

        for(int i=1; i<=N; ++i){
            friendList[i] = new ArrayList<>();
        }

        for(int i=0; i<M; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            friendList[u].add(v);
            friendList[v].add(u);
        }

        bfs();
        System.out.println(ans-1);
    }

}
