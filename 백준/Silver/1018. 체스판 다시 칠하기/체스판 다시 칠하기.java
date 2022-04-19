import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int case1 = 0;
        int case2 = 0;
        scan.nextLine();
        int result = 0, count = 0;
        String[][] str = new String[n][m];
        for (int i = 0; i < n; i++) {
            str[i] = scan.nextLine().trim().split("");
        }
        for (int i = 0; i < n - 7; i++) {
            for (int j = 0; j < m - 7; j++) {
                for (int x = i; x < 8 + i; x++) {
                    for (int y = j; y < 8 + j; y++) {
                        if (str[x][y].equals("B") && (x + y) % 2 == 0) {
                            case1++;
                        } else if (str[x][y].equals("B") && (x + y) % 2 == 1) {
                            case2++;
                        } else if (str[x][y].equals("W") && (y + x) % 2 == 0) {
                            case2++;
                        } else if (str[x][y].equals("W") && (y + x) % 2 == 1) {
                            case1++;
                        }
                    }
                }

                count = (case1 < case2 ? case1 : case2);
                if (i == 0 && j == 0)
                    result = count;

                if (result > count) {
                    result = count;
                }
                case1 = 0;
                case2 = 0;
            }
        }
        System.out.println(result);
        scan.close();
    }
}