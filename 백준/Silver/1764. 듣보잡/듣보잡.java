
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int sum = 0;

        List<String> arr = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        for(int i = 0; i < N; i++){
            map.put(br.readLine(), 0);
        }

        for(int i = 0; i < M; i++){
            String temp = br.readLine();
            if(map.containsKey(temp)){
                sum++;
                arr.add(temp);
            }
        }

        arr.sort(null);
        System.out.println(sum);
        for (String s : arr) {
            System.out.println(s);
        }
    }
}