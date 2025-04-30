import java.util.*;
import java.io.*;

public class Main {
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        String str = br.readLine();
        int[] arr = new int[26];

        for(int i = 0; i < str.length(); i++) {
            for(int j = 0; j < alphabet.length(); j++) {
                if(str.charAt(i) == alphabet.charAt(j)) {
                    arr[j]++;
                }
            }
        }

        for(int i = 0; i < arr.length; i++) {
            bw.write(arr[i] + " ");
        }
        bw.flush();
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
} 