class Solution {
    public int myAtoi(String s) {
        String str = s.trim();  
        int len = str.length(); 
        int i = 0;
        long sum = 0;  
        boolean isNeg = false;

        if (len == 0) {
            return 0; 
        }

        if (str.charAt(i) == '-') {
            isNeg = true;
            i++;
        } else if (str.charAt(i) == '+') {
            isNeg = false;
            i++;
        }

        for (; i < len; i++) {
            char ch = str.charAt(i);
            if (ch >= '0' && ch <= '9') {
                sum *= 10;
                sum += (ch - '0');

               
                if (sum > Integer.MAX_VALUE) {
                    return isNeg ? Integer.MIN_VALUE : Integer.MAX_VALUE;
                }
            } else {
                break;
            }
        }

        return (int)(isNeg ? -sum : sum);
    }
}
