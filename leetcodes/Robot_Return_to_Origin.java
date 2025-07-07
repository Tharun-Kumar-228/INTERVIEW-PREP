// class Solution {
//     public boolean judgeCircle(String moves) {
//         int[] pos = new int[2]; 

//         for (int i = 0; i < moves.length(); i++) {
//             char move = moves.charAt(i);

//             if (move == 'U') {
//                 pos[0]++;
//             } else if (move == 'D') {
//                 pos[0]--;
//             } else if (move == 'R') {
//                 pos[1]++;
//             } else if (move == 'L') {
//                 pos[1]--;
//             }
//         }
//         return pos[0] == 0 && pos[1] == 0;
//     }
// }
class Solution {
    public boolean judgeCircle(String moves) {
        int[] freq = new int[128];
        for (int i = 0; i < moves.length(); i++) {
            freq[moves.charAt(i)]++;
        }
        return freq['U'] == freq['D'] && freq['L'] == freq['R'];
    }
}