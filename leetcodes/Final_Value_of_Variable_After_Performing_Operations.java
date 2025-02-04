class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int count =0;
        for (String x:operations){
            if(x.equals("X++") || x.equals("++X")){
                count+=1;
            }
            else if(x.equals("X--") || x.equals("--X")){
                count-=1;
            }
        }
        return count;
    }
}