class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int rows  = matrix.length;
        int columns = matrix[0].length;
        HashMap <Integer,Integer> hm = new HashMap<>();
        List<Integer> lst = new ArrayList<>();
        for(int i=0;i<rows;i++){
           int min = matrix[i][0];
            for (int j = 1; j < columns; j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            hm.put(min, 1); 
        }
        for(int i = 0;i<columns;i++){
            int max = -1;
            for(int j=0;j<rows;j++){
                if(max< matrix[j][i]){
                    max = matrix[j][i];
                }
            }
            if(hm.containsKey(max)){
               hm.put(max,2); 
            }
        }
    for (Map.Entry<Integer,Integer> entry : hm.entrySet()) {
        if(entry.getValue() == 2){
            lst.add(entry.getKey());
        }
    }
    return lst;
    }
}