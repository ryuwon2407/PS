import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] num = new int[N];
        int[] sum = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            num[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < K; i++){ // 초기값 세팅
            sum[0] += num[i];
        }

        // 합의 최대 구하기
        int max = sum[0];
        for(int i = 0; i < N-K; i++){
            sum[i+1] = sum[i] - num[i] + num[i+K];
            max = Math.max(max, sum[i+1]);
        }

        System.out.println(max);
    }
}