class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length+nums2.length;
        int [] news = new int[n];
        int j=0;
        for(int i:nums1){
            news[j]=i;
            j++;
        }
        for(int i:nums2){
            news[j]=i;
            j++;
        }
        Arrays.sort(news);

        if(n%2 == 0){ 
             return (float) (news[n/2]+news[n/2 - 1])/2;
        }
        else {
              return (float) (news[n/2]); 
        }
    }
}