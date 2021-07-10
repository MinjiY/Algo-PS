package DataStructure;

import java.util.HashMap;
import java.io.*;
import java.util.Arrays;

public class BOJ_1302 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = 0;
        n= Integer.parseInt(br.readLine());
        HashMap<String, Integer> map = new HashMap<>();

        while((n--) != 0){
            String s = br.readLine();
            if(map.containsKey(s)){
                int temp = map.get(s);
                temp++;
                map.put(s,temp);
            }else{
                map.put("s",1);
            }
        }
    }
}
