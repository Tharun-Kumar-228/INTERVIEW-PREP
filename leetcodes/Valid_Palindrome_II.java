class Solution {
    public static String removeCharAt(String str, int index) {
            if (index < 0 || index >= str.length()) {
                throw new IllegalArgumentException("Index out of bounds");
            }
            return str.substring(0, index) + str.substring(index + 1);
        }
    public static String reverseName(String str) {
        return new StringBuilder(str).reverse().toString();
    }

    public boolean validPalindrome(String s) {
        int i=0,flag=1;
        int j = s.length() -1;

        int ind [] = new int[2];
        while(i<=j){
            if(s.charAt(i) == s.charAt(j)){
                i++;
                j--;
            }else{
                flag=0;
                ind[0]=i;
                ind[1]=j;
                break;
            }
        }
        if(flag==0){
        String s1 = removeCharAt(s,i);
        String s2 = removeCharAt(s,j);
        if(s1.equals(reverseName(s1)) || s2.equals(reverseName(s2))){
            return true;
        }else{
            return false;
        }
        }else{
            return true;
        }


        
        
    }
}