import java.util.*;
import java.io.*;

public class Main {
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int[] count1 = new int[26];
        int[] count2 = new int[26];
        
        String str1 = br.readLine();
        String str2 = br.readLine();
        
        // 첫 번째 단어의 알파벳 개수 세기
        for(char c : str1.toCharArray()) {
            count1[c - 'a']++;
        }
        
        // 두 번째 단어의 알파벳 개수 세기
        for(char c : str2.toCharArray()) {
            count2[c - 'a']++;
        }
        
        // 차이의 절대값 합산
        int result = 0;
        for(int i = 0; i < 26; i++) {
            result += Math.abs(count1[i] - count2[i]);
        }
        
        bw.write(String.valueOf(result));
        bw.flush();
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
} 