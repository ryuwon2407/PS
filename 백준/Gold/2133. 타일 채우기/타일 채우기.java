import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] DP = new int[N + 1];

        // 홀수 처리
        if (N % 2 != 0) {
            System.out.println(0);
            return;
        }

        DP[0] = 1;
        DP[1] = 0;
        DP[2] = 3;

        // 짝수만 될 수 있기 때문에 2씩 증가
        for (int i = 4; i <= N; i += 2) {
            DP[i] = DP[i - 2] * DP[2];

            // 불규칙 패턴 계산
            for (int j = i - 4; j >= 0; j -= 2) {
                DP[i] = DP[i] + (DP[j] * 2);
            }
        }

        System.out.println(DP[N]);
    }
}