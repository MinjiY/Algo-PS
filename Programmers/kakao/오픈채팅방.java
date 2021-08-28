package programmers.kakao_BlindRecruitment2019;
/*
    [Programmers] 2019 Kakao Blind Recruitment
 */
import java.util.ArrayList;
import java.util.HashMap;

public class 오픈채팅방 {
    public static String[] solution(String[] record) {
        ArrayList<String> arrList = new ArrayList<>();
        ArrayList<String> hash = new ArrayList<>();
        HashMap<String,String> hm = new HashMap<>();


        for(int i=0; i<record.length; ++i){
            String[] ord = record[i].split(" ");

            if(ord[0].equals("Enter")){
                hm.put(ord[1],ord[2]);
                arrList.add(ord[1]+"님이 들어왔습니다.");
                hash.add(ord[1]);
            }else if( ord[0].equals("Leave") ){
                arrList.add(ord[1]+"님이 나갔습니다.");
                hash.add(ord[1]);
            }else if(ord[0].equals("Change")){
                hm.put(ord[1],ord[2]);
            }
        }
        String[] answer = new String[arrList.size()];
        int indx= 0 ;
        for(int i=0; i<arrList.size(); ++i){
            String src = hash.get(i);
            String dest = hm.get(src);
            answer[indx++] = arrList.get(i).replace(src,dest);
        }

        return answer;
    }
    public static void main(String[] args){
        String[] record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
        solution(record);
    }
}
