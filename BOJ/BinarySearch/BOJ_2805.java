package BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
    [BOJ] 2805 나무자르기

    나무 M미터 필요
    절단기 높이 H 지정
    높이 H보다 큰 나무 위는 모두잘림
    20, 15, 10, 17일 때 높이H를 15로 지정했다면, 나무한번 잘랐을때 15, 15, 10, 15가 되고
    길이가 5, 2인 나무를 얻음 => 총 7미터
    나무를 필요한 만큼만 얻고자 할때, 적어도 M미터를 얻기위해 설정할 수 있는 높이의 최댓값
 */
public class BOJ_2805 {
    static int N;    //나무의 수, 얻고자하는 나무길이
    static long[] tree;
    static long M;
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    static long stol(String token){
        return Long.parseLong(token);
    }
    static boolean check(long len){
        long sum = 0;
        boolean flag = false;
        for(int i=0; i<N; ++i){
            sum += (Math.max(tree[i]-len,0));
        }
        if(sum >= M){
            flag = true;
        }
        else{
            flag = false;
        }
        return flag;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stol(st.nextToken());

        tree = new long[N];
        st = new StringTokenizer(br.readLine());
        long lo = 1;
        long hi = 0;
        long result = 0;
        for(int i=0; i<N; ++i){
            tree[i]= stol(st.nextToken());
            hi = Math.max(hi,tree[i]);
        }

        while(lo <= hi){
            long mid = (lo+hi)/2;

            if(check(mid)){
                result = mid;
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
        System.out.println(result);
    }
}
