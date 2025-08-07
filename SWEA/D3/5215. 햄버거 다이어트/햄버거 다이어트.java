import java.io.*;
import java.util.*;

public class Solution {
	static int N = 0, L = 0;
	static int max = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int t = 1; t <= T; t++) {
			max = 0;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			

			int[][] arr = new int[N][2];
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				arr[i][0] = Integer.parseInt(st.nextToken());
				arr[i][1] = Integer.parseInt(st.nextToken());
			}
			
			
			combination(arr, 0, 0, 0);
			System.out.println("#"+t+" "+max);
		}
			
		br.close();
	}
	
	static void combination(int[][] arr, int start, int sum, int score) {
		if(sum > L) return;
		if(score > max) max = score;
		
		for (int i = start; i < N; i++) {
	        combination(arr, i + 1, sum + arr[i][1], score + arr[i][0]);
	    }
	}
}