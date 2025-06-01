import java.util.*;
import java.io.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<>();
        
        for (String[] cloth : clothes) {
            map.put(cloth[1], map.getOrDefault(cloth[1], 0) + 1);
        }
        
        // 각 의상 종류별로 (의상 개수 + 1)을 곱함
        // +1은 해당 종류의 의상을 안 입는 경우
        for (String key : map.keySet()) {
            answer *= (map.get(key) + 1);
        }
        
        // 아무것도 안 입는 경우는 제외
        return answer - 1;
    }
}
