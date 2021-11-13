package programmers.kakao_BlindRecruitment2018;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

/*
    [Programmers] 2018 Kakao blind recruitment [1차] 추석 트래픽
    https://programmers.co.kr/learn/courses/30/lessons/17676

    초당 최대 처리량은 요청의 응답완료여부 관계없이 임의 시간부터 1초간 처리하는 최대 개수를 의미
    로그 문자열은 응답 완료시간 S, 처리시간 T가 공백으로 구분되어있다.

    S: 2016-09-15 hh:mm:ss.sss
    T: 0.1s

    2016-09-15 03:10:33.020 0.011s
    => 2016년 9월 15일 오전 3시 10분 33.010초부터 2016년 9월 15일 오전 3시 10분 33.020초 까지

    타임아웃이 3초라서 0.001 <= T <= 3.000
    타임아웃 존재하므로 날짜까지는 필요가 없다
    전부 밀리초단위로 만들어버려

    start 하는 시간 기준으로 term 더해서
 */
public class 추석트래픽 {

    public static int hourToSec(String hour){
        return Integer.parseInt(hour)*3600;
    }
    public static int minuteToSec(String minute){
        return Integer.parseInt(minute)*60;
    }
    public static int calProcess(int unit, ArrayList<int[]> timeList){
        int end = unit+1000;
        int start = unit;
        int cnt= 0 ;
        for(int i=0; i<timeList.size(); ++i) {
            int[] term = timeList.get(i);
            if( start <= term[1] && end > term[0]){     //확인하는 텀 이전에 시작했고, 확인하는 텀에 걸쳐있는애들
                cnt++;
            }

        }
        return cnt;
    }

    public static int solution(String[] lines) {
        ArrayList<int[]> timeList = new ArrayList<>();
        for(int i=0; i<lines.length; ++i){
            int sec = 0;
            String[] log = lines[i].split(" ");
            String sub = log[2].substring(0,log[2].length()-1);

            //처리시간
            String[] term = sub.split("\\.");

            int process= 0;
            process += Integer.parseInt(term[0]);
            process *= 1000;
            if(term.length > 1){                       //소수점자리 단위일때만
                process += Integer.parseInt(term[1]);
            }

            //응답 완료시간
            String[] time = log[1].split(":");
            sec += hourToSec(time[0]);
            sec += minuteToSec(time[1]);
            System.out.println(time[time.length-1]);
            String[] milli = time[time.length-1].split("\\.");
            sec += Integer.parseInt(milli[0]);
            sec = sec*1000;
            sec += Integer.parseInt(milli[1]);
            int[] startToEnd = {sec-process+1, sec};
            timeList.add(startToEnd);
        }
        int answer = 0;
        for(int i=0; i<timeList.size(); ++i){
            answer = Math.max(answer, calProcess(timeList.get(i)[0],timeList));
            answer = Math.max(answer,calProcess(timeList.get(i)[1],timeList)); //start 포함해서 1초가 더 max값인지, end포함해서 1초가 더 max인지
        }
        return answer;
    }
    public static void main(String[] args){
        //String[] lines = new String[10];
        //lines[0] = "2016-09-15 01:00:04.001 2.0s";
        //lines[1] = "2016-09-15 01:00:07.000 2s";

        String[] lines = {"2016-09-15 20:59:57.421 0.351s",
                "2016-09-15 20:59:58.233 1.181s",
                "2016-09-15 20:59:58.299 0.8s",
                "2016-09-15 20:59:58.688 1.041s",
                "2016-09-15 20:59:59.591 1.412s",
                "2016-09-15 21:00:00.464 1.466s",
                "2016-09-15 21:00:00.741 1.581s",
                "2016-09-15 21:00:00.748 2.31s",
                "2016-09-15 21:00:00.966 0.381s",
                "2016-09-15 21:00:02.066 2.62s"};
        System.out.println(solution(lines));
    }
}
