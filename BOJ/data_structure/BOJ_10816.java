package DataStructure;

import java.io.*;
import java.util.Map;
import java.util.HashMap;

public class BOJ_10816 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        br.readLine();
        String[] cards = br.readLine().split(" ");
        br.readLine();
        String[] numbers = br.readLine().split(" ");
        HashMap<String, Integer> map = new HashMap<>();

        for (int i =0; i <cards.length; ++i){
            map.put(cards[i],map.get(cards[i]) == null ? 1 : map.get(cards[i])+1);
        }
        for(int i=0; i<numbers.length; ++i){
            bw.write( (map.get(numbers[i]) == null ? 0 : map.get(numbers[i]))+" ");
        }
        bw.flush();
        bw.close();

    }
}
