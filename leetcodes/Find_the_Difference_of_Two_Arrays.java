// import java.util.*;

// class Solution {
//     public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
//         boolean[] freq1 = new boolean[2001]; 
//         boolean[] freq2 = new boolean[2001]; 

//         for (int n : nums1) {
//             freq1[n + 1000] = true;
//         }
//         for (int n : nums2) {
//             freq2[n + 1000] = true;
//         }

//         List<Integer> diff1 = new ArrayList<>();
//         List<Integer> diff2 = new ArrayList<>();

//         for (int n : nums1) {
//             if (freq1[n + 1000] && !freq2[n + 1000]) {
//                 diff1.add(n);
//                 freq1[n + 1000] = false; 
//             }
//         }

//         for (int n : nums2) {
//             if (freq2[n + 1000] && !freq1[n + 1000]) {
//                 diff2.add(n);
//                 freq2[n + 1000] = false;
//             }
//         }

//         List<List<Integer>> ans = new ArrayList<>();
//         ans.add(diff1);
//         ans.add(diff2);
//         return ans;
//     }
// }

import java.util.*;

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();

        
        for (int n : nums1) set1.add(n);
        for (int n : nums2) set2.add(n);

       
        List<Integer> diff1 = new ArrayList<>();
        for (int n : set1) {
            if (!set2.contains(n)) {
                diff1.add(n);
            }
        }

      
        List<Integer> diff2 = new ArrayList<>();
        for (int n : set2) {
            if (!set1.contains(n)) {
                diff2.add(n);
            }
        }

        List<List<Integer>> ans = new ArrayList<>();
        ans.add(diff1);
        ans.add(diff2);
        return ans;
    }
}

