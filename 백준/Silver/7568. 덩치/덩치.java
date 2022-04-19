import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int[] weight = new int[N];
        int[] height = new int[N];
        int[] result = new int[N];
        int i, j, idx, k, stu;

        for (i = 0; i < N; i++) {
            weight[i] = scan.nextInt();
            height[i] = scan.nextInt();
        }

        for (i = 0; i < N; i++) {
            for (j = 0, k = 1; j < N; j++) {
                if (weight[i] < weight[j] && height[i] < height[j]) {
                    k++;
                }
            }
            System.out.print(k + " ");
        }

        scan.close();
    }

}