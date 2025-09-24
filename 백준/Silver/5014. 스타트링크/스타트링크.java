import java.io.*;
import java.util.*;

public class Main {
	static int F, S, G, U, D;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		F = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		U = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		
		visited = new boolean[F+1];
		
		int temp = bfs();
		if(temp == -1) System.out.println("use the stairs");
		else System.out.println(temp);
		
		bfs();
	}
	
	public static int bfs() {
		Queue<Integer> q = new LinkedList<Integer>();
		int cnt = 0;
		
		q.offer(S);
		visited[S] = true;
		while(!q.isEmpty()) {
			int temp = q.size();
			for(int i = 0; i < temp; i++) {
				int num = q.poll();
				if(G == num) return cnt;
				
				if(num + U < F+1 && !visited[num + U]) { 
					visited[num + U] = true;
					q.offer(num + U);
				}
				if(num - D > 0 && !visited[num - D]) {
					visited[num - D] = true;
					q.offer(num - D);
				}
			}
			cnt++;
		}
		return -1;
	}
}