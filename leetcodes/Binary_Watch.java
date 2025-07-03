import java.util.ArrayList;
import java.util.List;
class Solution {
     private static int bitCountShift(int x) {
        int cnt = 0;
        while (x != 0) {      
            cnt += (x & 1);    
            x >>= 1;           
        }
        return cnt;
    }
    public List<String> readBinaryWatch(int turnedOn) {
         List<String> res = new ArrayList<>();
        for (int h = 0; h < 12; h++) {
            int hBits = bitCountShift(h);          
            for (int m = 0; m < 60; m++) {
                if (hBits + bitCountShift(m) == turnedOn) {
                    res.add(h + ":" + String.format("%02d", m));
                }
            }
        }
        return res;
    }
}