import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] R = new int[n];
        String[] str = new String[n];
        for (int i = 0; i < n; i++) {
            R[i] = scan.nextInt();
            str[i] = scan.nextLine();
        }
        for (int i = 0; i < n; i++) {
            for (int k = 1; k < str[i].length(); k++) {
                String[] s = str[i].split("");
                for (int j = 0; j < R[i]; j++) {
                    System.out.print(s[k]);
                }
            }
            System.out.println();
        }
        scan.close();
    }
}