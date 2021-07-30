package graph;
/*
    [BOJ] 16947 서울 지하철 2호선
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_16947 {
    static ArrayList<Integer>[] adj;
    static boolean[] visit;
    static int N;
    static int start;
    static int[] selected;
    static int[] cycle;
    static boolean flag = false;
    static int[] ans;

    // Cycle찾기
    static void dfs(int node, int cnt){
        // 방문 했던곳이고, 노드가 2개 이상(싸이클), 현재 경로에 존재하는지 확인
        if( visit[node] == true && cnt>2 && start == node){
            flag =true;                     // 찾음
            for(int i=0; i<cnt-1; ++i){     // 어떤 노드가 싸이클인지 배열에 체크
                cycle[selected[i]]= 1;
            }
            return;
        }

        for(int i=0; i<adj[node].size(); ++i){
            int next = adj[node].get(i);
            if(visit[next] == false){
                visit[next] = true;
                selected[cnt] = next;
                dfs(next,cnt+1);
                if(flag ==true){
                    return;
                }
                selected[cnt] = 0;
            }else{
                if(next == start && cnt>2){
                    selected[cnt] = next;
                    dfs(next,cnt+1);
                    if(flag ==true){
                        return;
                    }
                    selected[cnt] = 0;
                }
            }
        }
    }

    // 거리 구하기
    static void bfs(int node){
        Queue<NODE> q = new LinkedList<>();
        visit[node] = true;
        q.add(new NODE(node,0));

        while(!q.isEmpty()){
            NODE temp = q.poll();

            if(cycle[temp.node] == 1){
                ans[node]=temp.cnt;
                return;
            }

            for(int i=0; i<adj[temp.node].size(); ++i){
                int next = adj[temp.node].get(i);
                if(visit[next] == false){
                    visit[next] = true;
                    q.add(new NODE(next,temp.cnt+1));
                }
            }
        }

    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        adj = new ArrayList[N+1];
        visit = new boolean[N+1];
        selected = new int[N+1];
        cycle = new int[N+1];
        ans = new int[N+1];

        for(int i=1; i<=N; ++i) {
            adj[i] = new ArrayList<>();
        }

        for(int i=0; i<N; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            adj[v].add(u);
        }

        // cycle 구하기
        for(int i=1; i<=N; ++i){
            visit[i] = true;
            start = i;
            selected[0] = i;
            dfs(i,1);
            if(flag ==true){
                break;
            }
            Arrays.fill(visit,false);
        }

        // 거리 구하기
        for(int i=1; i<=N; ++i){
            if(cycle[i] == 0) {
                Arrays.fill(visit, false);
                bfs(i);
            }
        }

        for(int i=1; i<=N; ++i){
            System.out.print(ans[i]+" ");
        }

    }

    static class NODE{
        int node;
        int cnt;
        NODE (int node, int cnt){
            this.node = node;
            this.cnt = cnt;
        }
    }
}
