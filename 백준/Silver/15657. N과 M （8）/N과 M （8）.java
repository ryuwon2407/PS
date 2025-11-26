import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] num;

    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        num = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            num[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(num); //정렬
        dfs(new int[M],0, 0);
        System.out.print(sb.toString());
    }

    static void dfs(int[] arr, int m, int s){
        if(m == M){
            for(int i = 0; i < M; i++) sb.append(arr[i]).append(" ");
            sb.append("\n");
            return;
        }
        for(int i = s; i < N; i++){
            arr[m] = num[i];
            dfs(arr, m + 1, i);
        }
    }
}