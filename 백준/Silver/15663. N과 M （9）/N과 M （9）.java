import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] num, arr;
    static int[] cnt = new int[10001];
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        num = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
            cnt[num[i]] += 1;
        }
        num = Arrays.stream(num).distinct().toArray(); // 중복제거
        Arrays.sort(num); //정렬

        arr = new int[M];

        bfs(0);
        System.out.print(sb);
    }

    static void bfs(int m){
        if(m == M){
            for(int i = 0; i < M; i++) sb.append(arr[i]).append(" ");
            sb.append("\n");
            return;
        }
        for(int i = 0; i < num.length; i++){
            if(cnt[num[i]] != 0) {
                arr[m] = num[i];
                cnt[num[i]]--;
                bfs(m + 1);
                cnt[num[i]]++;
            }
        }
    }
}