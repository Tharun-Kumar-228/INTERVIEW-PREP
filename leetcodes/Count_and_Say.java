class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1"; 
        }
        String current = "1"; 
        for (int i = 2; i <= n; i++) { 
            String newStr = ""; 
            int count = 1; 
            for (int j = 1; j < current.length(); j++) {
                if (current.charAt(j) == current.charAt(j - 1)) {
                    count++;
                } else {
                    newStr += count + String.valueOf(current.charAt(j -1));
                    count = 1; 
                }
            }
           newStr += count + String.valueOf(current.charAt(current.length()-1));
           current = newStr; 
        }

        return current;
    }
}
