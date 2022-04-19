import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.Vector;

public class Main {

    private static int[] parent = new int[100000];
    private static int[] UnionFind = new int[100000];
    private static int[][] query = new int[1100000][2];
    private static int[] result = new int[1000000];
    private static int pre;

    private static Vector<Set<Integer>> color = new Vector<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int Q = Integer.parseInt(input[1]);
        UnionFind[0] = -1;
        pre = Q - 1;
        for (int i = 1; i < N; i++) {
            parent[i] = Integer.parseInt(br.readLine()) - 1;
            UnionFind[i]--;
        }
        for (int i = 0; i < N; i++) {
            Set<Integer> set = new HashSet<>();
            set.add(Integer.parseInt(br.readLine()));
            color.add(set);
        }
        for (int i = 0; i < Q + N - 1; i++) {
            input = br.readLine().split(" ");
            query[i][0] = Integer.parseInt(input[0]);
            query[i][1] = Integer.parseInt(input[1]) - 1;
        }
        for (int i = Q + N - 2; i >= 0; i--) {
            if (query[i][0] == 1) {
                Union(query[i][1], parent[query[i][1]]);
            } else {
                result[pre--] = color.get(find(query[i][1])).size();
            }
        }
        for (int i = 0; i < Q; i++) {
            bw.write(result[i] + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }

    public static void Union(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        if (UnionFind[x] < UnionFind[y]) {
            UnionFind[x] += UnionFind[y];
            color.get(x).addAll(color.get(y));
            UnionFind[y] = x;
        } else {
            UnionFind[y] += UnionFind[x];
            color.get(y).addAll(color.get(x));
            UnionFind[x] = y;
        }
    }

    public static int find(int x) {
        if (UnionFind[x] < 0) {
            return x;
        } else {
            int y = find(UnionFind[x]);
            UnionFind[x] = y;
            return y;
        }
    }
}