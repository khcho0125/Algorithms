import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int k = scan.nextInt();
        String str = scan.nextLine();
        Set<String> list = new HashSet<>();
        String[] result = new String[(n > k) ? n : k];
        int pre = 0;
        for (int i = 0; i < n; i++) {
            list.add(scan.nextLine());
        }
        for (int i = 0; i < k; i++) {
            str = scan.nextLine();
            if (list.contains(str)) {
                result[pre] = str;
                pre++;
            }
        }

        Arrays.sort(result, 0, pre);
        System.out.println(pre);
        for (int i = 0; i < pre; i++) {
            System.out.println(result[i]);
        }
        scan.close();
    }
}