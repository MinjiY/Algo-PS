package programmers.level1;

class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";

        int lefthand = 10;
        int righthand = 12;
        for(int i=0; i<numbers.length; ++i){
            if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
                answer +="L";
                lefthand = numbers[i];
            }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
                answer += "R";
                righthand = numbers[i];
            }else{
                int leftLength = getLength(lefthand,numbers[i]);
                int rightLength = getLength(righthand,numbers[i]);

                if (leftLength > rightLength){
                    answer += "R";
                    righthand = numbers[i];
                }else if( leftLength < rightLength){
                    answer += "L";
                    lefthand = numbers[i];
                }else{
                    if(hand.equals("right")){
                        answer += "R";
                        righthand = numbers[i];
                    }else{
                        answer += "L";
                        lefthand = numbers[i];
                    }
                }
            }
        }
        return answer;
    }
    public static int getLength(int index, int number){
        index = (index==0)?11 :index;
        number = (number == 0)?11 :number;

        int x = (index-1) /3; //1
        int y = (index-1)%3;    //0
        int numberX = number/3; // 1
        int numberY = 1;           //1

        return Math.abs(x-numberX)+ Math.abs(y-numberY);
    }
}