package brute_force.N과M;
/*
    [BOJ] 15666 N과 M(12)
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ_15666 {
    static int N, M;
    static int visit[] = new int[10001];
    static int selected[];
    static ArrayList<Integer> arrayList = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();

    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void solve(int indx, int cnt){
        if(cnt == M){
            for(int i=0; i<M; ++i){
                sb.append(arrayList.get(selected[i])+" ");
            }
            sb.append("\n");
            return;
        }
        for(int i=indx; i<arrayList.size(); ++i){
            selected[cnt] = i;
            solve(i,cnt+1);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());

        selected = new int[M+1];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i){
            int temp = stoi(st.nextToken());
            if(visit[temp] == 0){
                arrayList.add(temp);
                visit[temp]++;
            }
        }
        Collections.sort(arrayList);
        solve(0,0);
        System.out.println(sb);
    }
}
