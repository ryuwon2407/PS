import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int cnt = 0;
    static int[] map;
    static StringBuffer sb = new StringBuffer();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        map = new int[N];

        dfs(0);
        System.out.println(cnt);
    }
    
    public static void dfs(int row) {
        if (row == N) {
            cnt++;
            return;
        }

        // 이번 행에서 가능한 모든 열 시도
        for (int col = 0; col < N; col++) {
            map[row] = col;

            // 충돌하는지 안하는지 체크
            if (isPossible(row)){
                dfs(row+1);
            }
        }
    }

    public static boolean isPossible(int row) {
        for(int i = 0; i < row; i++){
            if(map[i] == map[row] && row != i) return false; // 같은 열 체크
            if(Math.abs(row - i) == Math.abs(map[row] - map[i])) return false;  // 같은 대각선 체크
        }
        return true;
    }
}

