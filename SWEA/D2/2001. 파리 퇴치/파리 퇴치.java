import java.io.*;
import java.util.*;

public class Solution {
	static int[][] map = new int[0][0];
	static int N = 0, M = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			map = new int[N][N];
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int max = 0;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					int temp = kill(i,j);
					if(max < temp) max = temp;
				}
			}
			
			System.out.println("#"+t+" "+max);
		}
		br.close();
	}
	
	//파리 죽이기
	public static int kill(int x, int y) {
		int sum = 0;
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < M; j++) {
				if(x+i < N && y+j < N) {
					sum += map[x+i][y+j];
				}
			}
		}
		return sum;
	}
}