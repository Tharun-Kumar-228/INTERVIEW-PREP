class Solution {
    public int numJewelsInStones(String j, String s) {
        boolean[] jewel = new boolean[123];

        for(int i = 0; i < j.length(); i++) 
        jewel[j.charAt(i)] = true;

        int count = 0;
        for(int i = 0; i < s.length(); i++) if(jewel[s.charAt(i)]) count++;

        return count;
        // int count =0;

        // HashSet<Character> hs = new HashSet<>();
        // for(char i : j.toCharArray()){
        //     hs.add(i);
        // }
        // for(char i : s.toCharArray()){
        //     if(hs.contains(i)){
        //         count++;
        //     }
        // }
        // return count;
    }
}