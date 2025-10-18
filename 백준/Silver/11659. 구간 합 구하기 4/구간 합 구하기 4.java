import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        int sum = 0; 
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N+1];
        
        arr[0] = 0;

        st = new StringTokenizer(br.readLine()); 
        for(int j =1 ;j <= N; j++){
            sum = sum +Integer.parseInt(st.nextToken());
            arr[j] = sum;
        }

        for(int m = 0; m < M; m++){
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());

            System.out.println(arr[j] - arr[i-1]);
        }
    }
}