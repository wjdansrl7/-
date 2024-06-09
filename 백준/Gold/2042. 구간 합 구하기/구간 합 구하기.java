import java.util.*;
import java.io.*;

public class Main {

    static void init(long[] a, long[] tree, int node, int start, int end) {
        // leaf node인 경우
        if (start == end) {
            tree[node] = a[start];
        } else {
            init(a, tree, node * 2, start, (start + end) / 2);
            init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    static long query(long[] tree, int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];

        long lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
        long rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        return lsum + rsum;
    }

    static void update(long[] a, long[] tree, int node, int start, int end, int index, long val) {
        if (index < start || index > end) {
            return;
        }
        if (start == end) {
            a[index] = val;
            tree[node] = val;
            return;
        }
        update(a, tree, node * 2, start, (start + end) / 2, index, val);
        update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        M += K;
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = Long.parseLong(br.readLine());
        }

        int h = (int) Math.ceil(Math.log(N) / Math.log(2));
        int tree_size = (1 << (h + 1));
        long[] tree = new long[tree_size];
        init(a, tree, 1, 0, N - 1);
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            if (A == 1) {
                int index = Integer.parseInt(st.nextToken());
                long val = Long.parseLong(st.nextToken());
                update(a, tree, 1, 0, N - 1, index - 1, val);
            } else {
                int left = Integer.parseInt(st.nextToken());
                int right = Integer.parseInt(st.nextToken());
                sb.append(query(tree, 1, 0, N - 1, left - 1, right - 1)).append('\n');
            }
        }
        System.out.println(sb);
    }
}