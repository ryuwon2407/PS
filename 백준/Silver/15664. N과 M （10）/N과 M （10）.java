import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] num, arr;

    static int[] cnt = new int[10001];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        num = new int[N];
        arr = new int[M];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
            cnt[num[i]]++;
        }

        Arrays.sort(num); // 정렬
        num = Arrays.stream(num).distinct().toArray(); // 중복제거

        bfs(0, 0);
        System.out.print(sb.toString());
    }

    public static void bfs(int m, int s){
        if (m == M){
            for(int i : arr) sb.append(i).append(" ");
            sb.append("\n");
            return;
        }

        for (int i = s; i < num.length; i++){
            if(cnt[num[i]] <= 0) continue;
            arr[m] = num[i];
            cnt[num[i]]--;
            bfs(m+1, i);
            cnt[num[i]]++;
        }
    }
}