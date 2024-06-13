import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        PriorityQueue<Long> pq = new PriorityQueue<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) pq.offer(Long.parseLong(st.nextToken()));
        while (m-- != 0) {
            long a1 = pq.poll();
            long a2 = pq.poll();

            pq.offer(a1 + a2);
            pq.offer(a1 + a2);
        }
        long result = 0;
        while (!pq.isEmpty()) result += pq.poll();
        System.out.println(result);
    }
}