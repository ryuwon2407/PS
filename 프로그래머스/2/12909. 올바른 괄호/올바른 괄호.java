class Solution {
    boolean solution(String s) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            // (일 경우 cnt++
            if (c == '(') {
                cnt++;
            } else {
                cnt--;
            }

            // cnt가 -일 경우 바로 false 리턴
            if (cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }
}