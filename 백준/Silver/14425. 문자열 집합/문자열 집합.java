import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int result = 0;
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        String[] S = new String[N];                     // 집합 S
        HashMap<String, Integer> map = new HashMap<>(); // 검사해야하는 문자열

        for (int i = 0; i < N; i++)
            S[i] = br.readLine();

        for (int i = 0; i < M; i++){
            String temp = br.readLine();
            map.put(temp, map.getOrDefault(temp, 0)+1);
        }
        
        for (int i = 0; i < N; i++)
            result += map.getOrDefault(S[i], 0);

        System.out.println(result);
    }
}