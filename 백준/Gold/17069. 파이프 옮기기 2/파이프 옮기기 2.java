import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] map;

    static final int H = 0;
    static final int V = 1;
    static final int DIAG = 2;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        map = new int[N][N];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        // DP
        long[][][] dp = new long[N][N][3];
        // DP 초기값
        dp[0][1][H] = 1;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if (i == 0 && j <= 1) continue;

                if(map[i][j] == 1) {
                    dp[i][j][H] = dp[i][j][V] = dp[i][j][DIAG] = 0;
                    continue;
                }

                if(j - 1 >= 0 && map[i][j-1] == 0)
                    dp[i][j][H] = dp[i][j-1][H] + dp[i][j-1][DIAG];
                if(i - 1 >= 0 && map[i-1][j] == 0)
                    dp[i][j][V] = dp[i-1][j][V] + dp[i-1][j][DIAG];
                if(i - 1 >= 0 && j - 1 >= 0)
                    if(map[i][j] == 0 && map[i-1][j] == 0 && map[i][j-1] == 0)
                        dp[i][j][DIAG] = dp[i-1][j-1][H] + dp[i-1][j-1][V] + dp[i-1][j-1][DIAG];
            }
        }

        //출력
        System.out.println(dp[N-1][N-1][H] + dp[N-1][N-1][V] + dp[N-1][N-1][DIAG]);
    }
}