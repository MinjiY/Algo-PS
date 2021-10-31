package programmers.kakao_BlindRecruitment2021;
/*
    [Programmers] 2021 Kakao Blind Recruitment
    https://programmers.co.kr/learn/courses/30/lessons/72411
 */
/*
    단품메뉴들로 새로 조합해서 코스요리 만들려고함
    가장 많이 함께 주문한 단품메뉴들로 코스요리 메뉴로 구성

    단, 코스요리 메뉴는 최소 2가지 이상의 단품메뉴
    최소 2명 이상의 손님으로부터 주문된 단품메뉴

    1. orders에서 course 갯수들 만큼 조합돌림
    2. map에 저장+ getOrDefault로 카운팅
 */

import java.util.*;

public class 메뉴리뉴얼 {
    static Map<String, Integer> hm;
    static ArrayList<String> arrayList;
    static int[] visit;
    static char[] selected;
    static int maxValue;

    static void dfs(String order, int M, int cnt, int indx){
        if(cnt == M){
            String tempStr="";
            for(int i=0; i<M; ++i){
                tempStr += selected[i];
            }
            char[] StringtoChar = tempStr.toCharArray();
            Arrays.sort(StringtoChar);

            int temp = hm.getOrDefault(String.valueOf(StringtoChar),0)+1;
            if(maxValue < temp){
                maxValue = temp;
            }
            hm.put(String.valueOf(StringtoChar), temp);
            return;
        }

        for(int i = indx; i<order.length(); ++i){
                selected[cnt]= order.charAt(i);
                dfs(order,M,cnt+1,i+1);
        }

    }
    static public String[] solution(String[] orders, int[] course) {

        arrayList = new ArrayList<>();
        for(int j=0; j<course.length; ++j){
            hm = new HashMap<>();
            maxValue = 2;
            for(int i = 0; i<orders.length; ++i){
                int length = orders[i].length();
                visit = new int[length];
                selected= new char[length];
                dfs(orders[i],course[j],0,0);
            }
            for(String key : hm.keySet()){
                if(hm.get(key) == maxValue){
                    arrayList.add(key);
                }
            }
        }
        Collections.sort(arrayList);
        String[] answer = new String[arrayList.size()];
        for(int i=0; i<arrayList.size(); ++i){
            answer[i] = arrayList.get(i);
            System.out.println(answer[i]);
        }
        return answer;
    }
    public static void main(String[] args){
        String[] orders ={"ABCDE", "AB", "CDAB", "ABDE", "XABYZ", "ABXYZ", "ABCD", "ABCDE", "ABCDE", "ABCDE", "AB", "AB", "AB", "AB", "AB", "AB", "AB", "AB", "AB", "AB"};
        int[] course = {2};
        System.out.println(solution(orders, course));

    }
}
