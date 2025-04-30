import java.util.*;
import java.io.*;

public class Main {
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int S = 0;

        int sum = 0;
        int[][] arr = new int[7][2];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            // arr[0] => 임시 temp 역할 
            arr[0][0] = Integer.parseInt(st.nextToken()); // 성별
            arr[0][1] = Integer.parseInt(st.nextToken()); // 학년
            
            arr[arr[0][1]][arr[0][0]]++;
        }

        for(int i = 1; i <= 6; i++) {
            for(int j = 0; j < 2; j++) {
                if (arr[i][j] % K == 0) {
                    S += arr[i][j] / K;
                } else {
                    S += arr[i][j] / K + 1;
                }
            }
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

// 남자는 남자끼리
// 여자는 여자끼리
// 한 방에는 같은 학년의 학생들
