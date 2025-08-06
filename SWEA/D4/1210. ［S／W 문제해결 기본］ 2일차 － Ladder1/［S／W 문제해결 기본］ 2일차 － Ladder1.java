import java.util.*;
import java.io.*;

public class Solution {
	static int[][] map = new int[100][100];
	static boolean[][] visited = new boolean[100][100];
	static int[] dx = {0, 0, -1};
	static int[] dy = {-1, 1, 0};
	static int t = 1;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(t = 1; t <= 10; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int T = Integer.parseInt(st.nextToken());
			
			for(int i = 0; i < 100; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < 100; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			for(int i = 0; i < 100; i++){
				if(map[99][i] == 2) {
					dfs(99, i);
				}
			}
			visited = new boolean[100][100];
		}
	}
	
	public static void dfs(int x, int y) {
		visited[x][y] = true;
		if(x == 0) {
			System.out.println("#"+t+" "+y);
			return;
		}
		
		for(int dir =0; dir < 3; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(nx >= 0 && ny >= 0 && nx < 100 && ny < 100) {
				if(!visited[nx][ny]) {
    				if(map[nx][ny] == 1) {
    					dfs(nx, ny);
    					break;
    				}
    				else if(dir == 2) {
    					dfs(nx, ny);
    				}
				}
			}
		}
		return;
	}
}