class Solution {
    public static boolean isVowel(char ch) {
        return "aeiouAEIOU".indexOf(ch) != -1;
    }

    public static boolean isConsonant(char ch) {
        return Character.isLetter(ch) && !isVowel(ch);
    }

    public static boolean isDigit(char ch) {
        return Character.isDigit(ch);
    }

    public boolean isValid(String word) {
        int len = word.length();
        int vowel = 0, consonant = 0;
        if (len < 3) {
            return false;
        }
        for (char ch : word.toCharArray()) {
            if (!Character.isLetterOrDigit(ch)) {
                return false; 
            }
            if (isVowel(ch)) {
                vowel++;
            } else if (isConsonant(ch)) {
                consonant++;
            }
        }
        return vowel > 0 && consonant > 0;
    }
}
