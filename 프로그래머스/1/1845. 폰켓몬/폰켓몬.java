import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] nums) {
        HashMap<String, Integer> map = new HashMap<>();
        
        for (int i : nums) { map.put(String.valueOf(i), map.getOrDefault(String.valueOf(i), 0) + 1); }

        if(map.size() <= nums.length / 2) { return map.size();
        } else { return (nums.length / 2); }
    }
}