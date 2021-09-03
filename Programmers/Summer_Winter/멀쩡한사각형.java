package programmers.SummerWinter2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class 멀쩡한사각형 {
    static int gcd(int a, int b){
        while(b!=0){
            int r = a%b;
            a=b;
            b= r;
        }
        return a;
    }
    static long solution(int w, int h) {
        long answer = 1;
        int gcd_v = gcd(w,h);
        answer = ((long)w*(long)h)-((long)w+(long)h-(long)gcd_v);
        return answer;
    }
    public static void main(String[] args) throws IOException {
        System.out.println(solution(8,12));
    }
}
