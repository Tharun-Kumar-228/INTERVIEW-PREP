class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String code [] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashSet<String> hs = new HashSet<>();

        int k=-1;
        for(String a: words){
            StringBuilder ans = new StringBuilder();
            for(char ch : a.toCharArray()){
                ans.append(code[ch-'a']);
            }
            hs.add(ans.toString());
        }
        return hs.size();
        
    }
}