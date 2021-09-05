package BinarySearch;

/*
    [BOJ] 1654 랜선 자르기

    N개의 같은 길이의 랜선을 만들어야함
    K개 랜선 이미 있음
    300cm에서 140짜리 랜선 두개 잘라내면 나머지 20은 버려야함
    손실되는 길이 없다고 가정하고 K개로 N개 랜선 못만드는 경우는 없다고 가정
    N개보다 많이 만드는 것도 N개를 만드는 것에 포함
    만들 수 있는 최대 랜선의 길이
    1<= K <= 10000
    1<= N <= 1000000
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1654 {
    static long[] wire;
    static int N, K;
    static boolean possible(long len){
        int cnt = 0;
        boolean flag = false;
        for(int i=0; i<K; ++i){
            cnt += (wire[i]/len);
        }
        if(cnt < N){
            flag = false;
        }else{
            flag = true;
        }
        return flag;
    }
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = stoi(st.nextToken());
        N = stoi(st.nextToken());

        wire = new long[K];
        long lo = 1;
        long hi = 0;
        long result = 0;
        for(int i=0; i<K; ++i){
            wire[i] = stoi(br.readLine());
            hi = Math.max(hi,wire[i]);
        }

        while(lo <=hi){
            long mid = (lo+hi)/2;

            if(possible(mid)){
                result = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        System.out.println(result);

    }
}
