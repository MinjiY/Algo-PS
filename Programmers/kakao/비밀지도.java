package programmers.kakao_BlindRecruitment2018;

import java.util.ArrayList;

/*
    [Programmers] 2018 Kakao blind Recruitment [1차]비밀지도
    https://programmers.co.kr/learn/courses/30/lessons/17681

    이진수스트링
*/
public class 비밀지도 {
    public static String[] toBinary(int[] arr){
        int binaryLength = 0;
        String[] result = new String[arr.length];
        for(int i =0; i<arr.length; ++i) {
            int num = arr[i];
            StringBuilder binary = new StringBuilder();

            while (num != 0) {
                binary.append(String.valueOf(num % 2));
                num = num / 2;
            }
            if(arr.length > binary.length()){
                while(arr.length != binary.length()){
                    binary.append("0");
                }
            }
            result[i] = binary.reverse().toString();
        }
        return result;
    }

    public static String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[arr1.length];
        //ArrayList<String> answer = new ArrayList<>();
        String[] arr1String = toBinary(arr1);
        String[] arr2String = toBinary(arr2);
        String temp = "";

        for(int i=0; i<arr1String.length; ++i){
            for(int j=0; j<arr1String[i].length(); ++j){
                if(arr1String[i].charAt(j) == '1' || arr2String[i].charAt(j) == '1'){
                    temp += "#";
                }else if(arr1String[i].charAt(j) == '0' && arr2String[i].charAt(j)=='0' ){
                    temp += " ";
                }
            }
            answer[i] = temp;
            temp = "";
        }

        return answer;
    }
    public static void main(String[] args){
        int[] arr1 = {9, 20, 28, 18, 11};
        int[] arr2 = {30, 1, 21, 17, 28};
        String[] ans = solution(5,arr1,arr2);
        for(int i=0; i<ans.length; ++i){
            System.out.println(ans[i]);
        }
    }
}
