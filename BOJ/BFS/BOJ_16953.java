package BFS;
/*
    [BOJ] 16953 A->B
    BFS 풀이
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
public class BOJ_16953 {
    static String A;
    static String B;
    static HashMap<String, Integer> visit = new HashMap<>();
    static int ans;
    static void bfs(){
        Queue<NODE> q = new LinkedList<>();
        q.add(new NODE(A, 0));


        while(!q.isEmpty()){
            NODE temp = q.poll();
            String curNode = temp.node;
            int cnt = temp.cnt;


            if(curNode.equals(B)){
                //찾음
                ans = cnt;
                return;
            }else if(curNode.length() > B.length()){
                continue;
            }
            else{
                long tempNode = Long.parseLong(curNode)*2;
                String tempNodeStr= String.valueOf(tempNode);
                if(visit.get(tempNodeStr) == null){
                    visit.put(tempNodeStr,1);
                    q.add(new NODE(String.valueOf(tempNode),cnt+1));
                }
                if( visit.get(curNode+"1") == null){
                    curNode+="1";
                    visit.put(curNode,1);
                    q.add(new NODE(curNode, cnt+1));
                }
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = st.nextToken();
        B = st.nextToken();

        if(A.equals(B)){
            System.out.println(1);
        }else{
            bfs();
            if(ans == 0) {
                System.out.println("-1");
            }else{
                System.out.println(ans + 1);
            }
        }
    }
    static class NODE{
        String node;
        int cnt;
        NODE(String node, int cnt){
            this.node= node;
            this.cnt = cnt;
        }
    }
}
