import java.io.*;
import java.util.*;

public class Main {
	static int N, M;
	static int[] list;
	static int[] outList;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		list = new int[N];
		outList = new int[N];
		visited = new boolean[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i < N; i++)
			list[i] = Integer.parseInt(st.nextToken());
		
		Arrays.sort(list);
		dfs(0);
	}
	
	public static void dfs(int level) {
		if(level == M) {
			for(int i = 0; i < M; i++)
				System.out.print(outList[i]+" ");
			System.out.println();
			return;
		} else {
			for(int i = 0; i < list.length; i++) {
				if(!visited[i]) {
					outList[level]=list[i];
					visited[i]=true;
					dfs(level+1);
					visited[i]=false;
				}
			}
		}
	}
}