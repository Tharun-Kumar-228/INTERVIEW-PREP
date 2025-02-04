class Solution {
    public boolean wordPattern(String pattern, String s) {
        String arr[] = s.split(" ");
        HashMap <Character,String> mapping = new HashMap<>();
        HashSet <String> seen = new HashSet<>();
        if(pattern.length() != arr.length) {
            return false;
        }else{
            for(int i=0;i<pattern.length();i++){
                char c = pattern.charAt(i);
                String words = arr[i];
                if(mapping.containsKey(c)){
                        if(!mapping.get(c).equals(words)){
                            return false;
                        }
                }else{
                    if(seen.contains(words)){
                        return false;
                    }
                    mapping.put(c,words);
                    seen.add(words);
                }
            }
        return true;
        }
    }
}