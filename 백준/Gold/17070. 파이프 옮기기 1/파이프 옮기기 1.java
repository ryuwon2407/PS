import java.util.*;
import java.io.*;

public class Main {
    static int N, result = 0;
    static int[][] map;
    static boolean[][] visited;

    static int[][][] pipe = {{{0,1},{1,1}},        //가로 -> 가로, 대각
                             {{1,0},{1,1}},        //세로 -> 세로, 대각
                             {{0,1},{1,0},{1,1}}}; //대각 -> 가로, 세로, 대각
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        visited = new boolean[N][N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        visited[0][0] = visited[0][1] = true;
        dfs(new int[]{0,1}, 0);
        System.out.println(result);
    }

    public static void dfs(int[] temp, int s) {
        if (temp[0] == N-1 && temp[1] == N-1){
            result++;
            return;
        }

        if (s == 0 || s == 1) {
            if(temp[0]+pipe[s][0][0] < N && temp[1]+pipe[s][0][1] < N )
                if(map[temp[0]+pipe[s][0][0]][temp[1]+pipe[s][0][1]] == 0)
                    dfs(new int[]{temp[0]+pipe[s][0][0], temp[1]+pipe[s][0][1]}, s);// 가로 or 세로
            if(temp[0]+pipe[s][1][0] < N && temp[1]+pipe[s][1][1] < N)
                if(map[temp[0]+pipe[s][1][0]][temp[1]+pipe[s][1][1]] == 0 &&
                    map[temp[0]+1][temp[1]] == 0 &&
                    map[temp[0]+1][temp[1]+1] == 0 &&
                    map[temp[0]][temp[1]+1] == 0)
                    dfs(new int[]{temp[0]+pipe[s][1][0], temp[1]+pipe[s][1][1]}, 2);// 대각
        } else {
            if(temp[0]+pipe[s][0][0] < N && temp[1]+pipe[s][0][1] < N)
                if(map[temp[0]+pipe[s][0][0]][temp[1]+pipe[s][0][1]] == 0)
                    dfs(new int[]{temp[0]+pipe[s][0][0], temp[1]+pipe[s][0][1]}, 0);// 가로
            if(temp[0]+pipe[s][1][0] < N && temp[1]+pipe[s][1][1] < N)
                if(map[temp[0]+pipe[s][1][0]][temp[1]+pipe[s][1][1]] == 0)
                    dfs(new int[]{temp[0]+pipe[s][1][0], temp[1]+pipe[s][1][1]}, 1);// 세로
            if(temp[0]+pipe[s][2][0] < N && temp[1]+pipe[s][2][1] < N)
                if(map[temp[0]+pipe[s][2][0]][temp[1]+pipe[s][2][1]] == 0&&
                    map[temp[0]+1][temp[1]] == 0 &&
                    map[temp[0]+1][temp[1]+1] == 0 &&
                    map[temp[0]][temp[1]+1] == 0)
                    dfs(new int[]{temp[0]+pipe[s][2][0], temp[1]+pipe[s][2][1]}, 2);// 대각
        }
    }
}