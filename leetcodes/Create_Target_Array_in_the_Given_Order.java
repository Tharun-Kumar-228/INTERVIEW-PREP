class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList <Integer> arrLst = new ArrayList<>();
        for(int i =0;i<index.length;i++){
            arrLst.add(index[i],nums[i]);
        }
        int [] arr = new int[arrLst.size()];
        for(int i=0;i<arrLst.size();i++){
            arr[i]=arrLst.get(i);
        }
        return arr;
    }
}