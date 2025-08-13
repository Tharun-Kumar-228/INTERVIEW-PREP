import java.util.*;

class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> unique = new HashSet<>();
        
        for (String email : emails) {
            String[] parts = email.split("@", 2); // local and domain
            String local = parts[0];
            
            int plusIndex = local.indexOf('+');
            if (plusIndex != -1) {
                local = local.substring(0, plusIndex);
            }
            local = local.replace(".", "");
            
            unique.add(local + "@" + parts[1]);
        }
        
        return unique.size();
    }
}
