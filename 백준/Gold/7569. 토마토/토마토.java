import java.io.*;
import java.util.*;

public class Main {
    static int N, M, H;
    static int cnt = 0;
    static int[][][] map;
    static Queue<tomato> q = new LinkedList<>();
    
    // 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
    static int[] dx = {-1, 1, 0, 0, 0, 0};
    static int[] dy = {0, 0, -1, 1, 0, 0};
    static int[] dz = {0, 0, 0, 0, -1, 1};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        M = Integer.parseInt(st.nextToken()); // 가로
        N = Integer.parseInt(st.nextToken()); // 세로
        H = Integer.parseInt(st.nextToken()); // 높이
        
        map = new int[H][N][M];
        for(int h = 0; h < H; h++) {
            for(int n = 0; n < N; n++) {
                st = new StringTokenizer(br.readLine());
                for(int m = 0; m < M; m++) {
                    int temp = Integer.parseInt(st.nextToken());
                    map[h][n][m] = temp;
                    
                    if(temp == 1) {
                        q.offer(new tomato(h,n,m));
                    } else if(temp == 0) {
                        cnt++;
                    }
                }
            }
        }
        System.out.println(bfs());
    }
    
    public static int bfs() {
        int days = 0;
        
        if(cnt == 0) return 0;
        
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                tomato t = q.poll();
                
                for(int dir = 0; dir < 6; dir++) {
                    int nh = t.h + dx[dir];
                    int nn = t.n + dy[dir];
                    int nm = t.m + dz[dir];
                    
                    if(nh >= 0 && nh < H && nn >= 0 && nn < N && nm >= 0 && nm < M) {
                        if(map[nh][nn][nm] == 0) {
                            map[nh][nn][nm] = 1;
                            q.offer(new tomato(nh, nn, nm));
                            cnt--;
                        }
                    }
                }
            }
            days++;
        }
        
        if (cnt > 0) return -1;
        return days - 1;
    }
}

class tomato {
    int h, n, m;
    tomato(int h, int n, int m){
        this.h = h;
        this.n = n;
        this.m = m;
    }
}
