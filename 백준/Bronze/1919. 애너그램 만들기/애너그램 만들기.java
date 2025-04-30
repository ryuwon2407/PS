import java.util.*;
import java.io.*;

public class Main {
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        int[][] arr = new int[2][26];
        int S = 0;
        String str = "";

        for(int i = 0; i < 2; i++) {
            str = br.readLine();

            for(int j = 0; j < str.length(); j++) {
                for(int k = 0; k < alphabet.length(); k++) {
                    if(str.charAt(j) == alphabet.charAt(k)) {
                        arr[i][k]++;
                    }
                }
            }
        }
        
        for(int i = 0; i < 26; i++) {
            S += Math.abs(arr[0][i] - arr[1][i]);
        }

        bw.write(S + "");
        bw.flush();
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
} 
