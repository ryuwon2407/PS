import java.io.*;
import java.util.*;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static boolean[] visited;
	static int N = 0, M = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		int[] sel = new int[M];
		visited = new boolean[N];

		dfs(sel,0);
		System.out.print(sb);
		br.close();
	}
	
	public static void dfs(int[] sel, int cnt) {
		if(cnt == M) {
			for (int i = 0; i < M; i++) sb.append(sel[i]).append(' ');
			sb.append('\n');
			return;
		} else {
			for(int i = 0; i < N; i++) {
				if(!visited[i]) {
					visited[i] = true;
					sel[cnt] = i + 1;
					dfs(sel,cnt+1);
					visited[i] = false;
				}
			}
		}
	}
}