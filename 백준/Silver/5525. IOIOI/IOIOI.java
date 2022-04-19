import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        scan.nextLine();
        String input = scan.nextLine();
        String[] str = input.split("I");
        String[] last = input.split("");
        int length = str.length;
        int pre = 0, result = 0;
        boolean stack = false;
        int check = last[last.length - 1].equals("O") ? 1 : 0;

        for (int i = n; i < length - check; i++) {
            if (stack && str[i].equals("O")) {
                result++;
                pre++;
            } else if (stack && !str[i].equals("O")) {
                stack = false;
                i = pre + n - 1;
                pre++;
            } else {
                for (; pre <= i; pre++) {
                    if (!str[pre].equals("O")) {
                        i = pre + n - 1;
                        pre++;
                        break;
                    }
                    if (pre == i) {
                        result++;
                        stack = true;
                    }
                }
            }
        }
        System.out.println(result);
        scan.close();
    }
}