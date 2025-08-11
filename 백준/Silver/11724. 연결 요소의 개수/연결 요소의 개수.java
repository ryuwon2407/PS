import java.io.*;
import java.util.*;

public class Main {
	static List<Integer>[] adj;
	static boolean[] visited = new boolean[0];
	static int N = 0, M = 0, num = 0;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		adj = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) adj[i] = new ArrayList<>();
		visited = new boolean[N+1];
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			
			adj[u].add(v);
			adj[v].add(u);
		}
		
		for(int i = 1; i <= N; i++) {
			if(!visited[i]) {
				check(i);
				num++;
			}
		}
		
		System.out.println(num);
	}

	
	public static void check(int node) {
		visited[node] = true;
		for(int i : adj[node]) {
			if (!visited[i]) check(i);
		}
	}
}
