class Solution {
    public char findTheDifference(String s, String t) {
        char Ans =0;
        for(char i : s.toCharArray()){
            Ans ^= i;
        }
        
        for(char i : t.toCharArray()){
            Ans ^= i;
        }
        return Ans;
    }
}