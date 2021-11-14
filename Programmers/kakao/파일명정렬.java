package programmers.kakao_BlindRecruitment2018;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;

/*
    [Programmers] 2018 Kakao blind Recruitment > [3차] 파일명 정렬
    https://programmers.co.kr/learn/courses/30/lessons/17686

    파일명은 100글자 이내로, 대소문자, 숫자, 공백, 마침표, 뺴기부호

    파일명은 HEAD, NUMBER, TAIL의 세 부분으로 구성
    HEAD : 숫자가 아닌 문자로 이루어져있음, 1글자 이상
    NUMBER: 최대 다섯글자의 연속, 1글자 이상, 0~99999 , 00000이나 0101도 가능
    TAIL: 숫자도 가능 아무거나 가능, 아무 글자도 없을 수 있음

    1. 파일명은 HEAD 먼저정렬, 사전 순, 대소문자구분 x
    2. HEAD가 대소문자 차이 외에 같을 경우, NUMBER의 숫자 순으로 9 < 10 < 0011 < 012 < 13 < 014
        숫자 앞의 0은 무시되며 012 = 12
    3. HEAD와 NUMBER의 숫자도 같을 경우, 원래 입력에 주어진 순서를 유지한다.
        MUZI01.zip 과 muzi1.png가 입력으로 들어오면 정렬후에도 두 파일의 순서가 바뀌어서는 안된다.


 */
public class 파일명정렬 {

    public static int convertNum(String str, String head){
        str = str.substring(head.length()); // 숫자부터 시작
        String result = "";
        for(char c : str.toCharArray()){
            if(Character.isDigit(c) && result.length() < 5) // 숫자인지, result길이가 5를 안넘는지
            {
                result += c;
            }else
                break;
        }
        return Integer.valueOf(result);
    }
    public static String[] solution(String[] files) {
        String[] answer = {};
        Arrays.sort(files, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                //HEAD
                String head1 = o1.split("[0-9]")[0];
                String head2 = o2.split("[0-9]")[0];

                //소문자로 변경
                int result = head1.toLowerCase().compareTo(head2.toLowerCase());

                // 같은 문자일 경우 0을 반환, 비교하는 값보다 작으면 음수, 크면 양수
                if(result == 0){
                    //숫자로 비교
                    result = convertNum(o1, head1) - convertNum(o2, head2);
                }
                return result;
            }
        });

        return files;
    }

    public static void main(String[] args){
        String[] input = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG","F-15"};
        //String[] input = {"F-15"};

        String[] output = solution(input);
        for(int i=0; i< output.length; ++i){
            System.out.println(output[i]);
        }
    }
}
