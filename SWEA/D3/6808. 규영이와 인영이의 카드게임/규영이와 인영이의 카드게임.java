import java.util.*;
import java.io.*;
 
public class Solution {
    static int score_me = 0;
    static int score_you = 0;
 
    static boolean[] visited = new boolean[9];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
 
        for(int t = 1; t <= T; t++) {
            ArrayList<Integer> num = new ArrayList<>(Arrays
                .asList(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18));
 
            int[] me = new int[9];
            int[] your = new int[9];
 
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < 9; i++) { //내 배열 담기
                int temp = Integer.parseInt(st.nextToken());
                me[i] = temp;
                num.remove(num.indexOf(temp));
            }
 
            //상대 배열 담기
            for (int i = 0; i < num.size(); i++) {
                your[i] = num.get(i);
            }
 
            dfs(new int[9], me, your, 0, 9, 9);
            System.out.println("#" + t + " " + score_me + " " + score_you);
 
            score_me = 0;
            score_you = 0;
            visited = new boolean[9];
        }
    }
    static void dfs(int select[], int me[], int your[], int cnt, int n, int k) {
        if (cnt == k) {
            play(select, your);
            return;
        }
 
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                select[cnt] = me[i];
                visited[i] = true;
                dfs(select, me, your, cnt + 1, n, k);
                visited[i] = false;
            }
        }
    }
 
    static void play(int[] me, int[] your) {
        int meScore = 0;
        int yourScore = 0;
 
        for(int i = 0; i < 9; i++) {
            if(me[i] > your[i]) meScore += me[i] + your[i];
            else if(me[i] < your[i]) yourScore += me[i] + your[i];
        }
 
        if(meScore > yourScore) score_me++;
        else if(meScore < yourScore) score_you++;
    }
}