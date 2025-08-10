class Solution {
    public boolean checkIfPangram(String s) {
        int mask = 0;
        
        for (char c : s.toCharArray()) {
            mask |= 1 << (c - 'a'); 
            if (mask == (1 << 26) - 1) { 
                return true;
            }
        }
        
        return mask == (1 << 26) - 1;
    }
}
