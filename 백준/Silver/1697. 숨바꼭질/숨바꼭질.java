import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int k = scan.nextInt();
        int cnt, pre = 0, temp, size;
        List<Integer> stack = new ArrayList<>();
        int[] map = new int[200001];
        if (n >= k) {
            System.out.println(n - k);
            scan.close();
            return;
        }
        map[n] = 1;
        stack.add(n);
        for (cnt = 1; n != k; cnt++) {
            size = stack.size();
            for (pre = 0; pre < size; pre++) {
                temp = stack.get(pre);
                if (k == temp * 2 || k == temp + 1 || k == temp - 1) {
                    System.out.println(cnt);
                    scan.close();
                    return;
                }
                if (temp < k) {
                    if (map[temp * 2] == 0) {
                        stack.add(temp * 2);
                        map[temp * 2] = 1;
                    }
                    if (map[temp + 1] == 0) {
                        stack.add(temp + 1);
                        map[temp + 1] = 1;
                    }
                }
                if (temp != 0 && map[temp - 1] == 0) {
                    stack.add(temp - 1);
                    map[temp - 1] = 1;
                }
            }
        }
    }
}