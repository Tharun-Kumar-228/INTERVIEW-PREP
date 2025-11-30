class Solution {
    private static final int[] vals = new int[] {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    private static final String[] symbols = new String[] {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    // out side - one time declaration only
    //private  - accessed only within class
    //static - only  for the object 
    // final  - constant 
    public String intToRoman(int num) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < vals.length && num >= 0; i++) {
            while (num >= vals[i]) {
                num -= vals[i];
                res.append(symbols[i]);
            }
        }
        return res.toString();
    }
}