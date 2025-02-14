import java.util.ArrayList;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        ArrayList<Character> magazineList = new ArrayList<>();
        for (char c : magazine.toCharArray()) {
            magazineList.add(c);
        }
        
        for (char c : ransomNote.toCharArray()) {
            if (!magazineList.remove((Character) c)) {
                return false;
            }
        }
        
        return true;
    }
}