package DataStructure;
/*
    [BOJ] 1302 베스트셀러
 */
import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class BOJ_1302 {
    static int stoi(String token){
        return Integer.parseInt(token);
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = 0;
        n= stoi(br.readLine());
        HashMap<String, Integer> hm = new HashMap<>();

        for(int i=0; i<n; ++i){
            String temp = br.readLine();
            int cnt = hm.getOrDefault(temp,0);
            hm.put(temp,cnt+1);
        }

        int MAX = 0;
        String cur = "";

        for (String key: hm.keySet()){
            int value = hm.get(key);
            if(MAX<value){
                MAX = value;
                cur = key;
            }else if( MAX == value && cur.compareTo(key)>0){
                MAX = value;
                cur = key;
            }
        }
        System.out.println(cur);
    }
}
