package brute_force;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_15658 {
    static int[] operator = new int[4];
    static int[] arr;
    static int[] selected;
    static int MAX = Integer.MIN_VALUE;
    static int MIN = Integer.MAX_VALUE;
    static int N;

    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static void solve(){
        int temp=arr[0];
        for(int i=0; i<(N-1); ++i){
            switch(selected[i]){
                case 0:
                    temp = temp+arr[i+1];
                    break;
                case 1:
                    temp = temp-arr[i+1];
                    break;
                case 2:
                    temp = temp*arr[i+1];
                    break;
                case 3:
                    temp = temp/arr[i+1];
                    break;
            }
        }
        if(MAX < temp){
            MAX = temp;
        }
        if(MIN>temp ){
            MIN = temp;
        }
    }
    static void permutation(int cnt){
        if(cnt == N-1){

            solve();
            return;
        }

        for(int i=0; i<4; ++i){
            if(operator[i] > 0){
                operator[i]--;
                selected[cnt] = i;
                permutation(cnt+1);
                operator[i]++;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = stoi(br.readLine());
        arr = new int[N];
        selected = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0 ;i< N; ++i){
            arr[i] = stoi(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<4; ++i){
            operator[i] = stoi(st.nextToken());
        }
        permutation(0);
        System.out.println(MAX);
        System.out.println(MIN);

    }
}
