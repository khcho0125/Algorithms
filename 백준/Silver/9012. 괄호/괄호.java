import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        scan.nextLine();
        int i, j, pre;
        int[] stack = new int[52];
        String[] str;
        boolean NO = false;
        for (i = 0; i < N; i++) {
            str = scan.nextLine().split("");
            NO = false;
            for (j = 0, pre = 1; j < str.length; j++) {
                if (str[j].equals("(")) {
                    stack[pre] = 1;
                    pre++;
                } else if (str[j].equals(")")) {
                    if (stack[pre - 1] == 1) {
                        pre--;
                        stack[pre] = 0;
                    } else {
                        NO = true;
                        break;
                    }
                }
            }
            if (NO || stack[1] != 0) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }

    }

}