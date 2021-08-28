package programmers.kakao_BlindRecruitment2020;
/*
    [Programmers] 2020 Kakao Blind Recruitment
 */

public class 문자열압축 {
    public static int solution(String s) {
        int answer = Integer.MAX_VALUE;

        for(int i=s.length()/2; i>0; --i){
            int start = 0;
            int end = i;
            String pre = "";
            String ans = "";
            int cnt=1;
            while(start <= (s.length()-i) ){
                String temp = s.substring(start,end);
                //System.out.println(temp);
                if(temp.equals(pre)){           //이전 문자열과 같다
                    cnt++;
                }else if(temp.equals(pre) == false){    //이전 문자열과 다르다
                    //1일땐 생략가능이니까 cnt는 안합침
                    if(cnt == 1){
                        ans+=pre;
                    }else{
                        ans+=cnt;
                        ans+=pre;
                    }
                    cnt =1;
                    pre = temp;
                }
                //서브스트링 짜를때 0-2 => 2-4 => 4-6 이런 패턴으로 만드려고
                start = end;
                end = end+i;
            }
            //pre랑 cnt에 마지막에 남아있는거 처리
            if(cnt == 1){
                ans+=pre;
            }else{
                ans+=cnt;
                ans+=pre;
            }
            // ex) aabbac|cc => 3개씩 쪼갰을때 남는 여분문자열 처리
            if(start<s.length()){
                ans+= (s.substring(start,s.length()));
            }

            if(answer > ans.length() ){
                answer = ans.length();
            }

            //System.out.println(ans);
        }
        //s.length()가 1일때 어차피 for못들어감 => if else안해준 이유, length가 1일 때 답은 1!
        if(s.length() == 1){
            answer = 1;
        }
        return answer;
    }
    public static void main(String[] args){
        String str = "a";
        System.out.println(solution(str));

    }
}
