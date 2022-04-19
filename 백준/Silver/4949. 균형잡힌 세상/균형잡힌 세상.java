import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        String[] written;
        int[] stack = new int[102];
        int pre = 1, i = 0;
        boolean No = false;

        while (!str.equals(".")) {
            Arrays.fill(stack, 0);
            pre = 1;
            No = false;
            for (written = str.split(""), i = 0; !written[i].equals("."); i++) {
                if (written[i].equals("(")) {
                    stack[pre] = 1;
                    pre++;
                } else if (written[i].equals("[")) {
                    stack[pre] = 2;
                    pre++;
                } else if (written[i].equals(")")) {
                    if (stack[pre - 1] == 1) {
                        pre--;
                        stack[pre] = 0;
                    } else {
                        No = true;
                        break;
                    }
                } else if (written[i].equals("]")) {
                    if (stack[pre - 1] == 2) {
                        pre--;
                        stack[pre] = 0;
                    } else {
                        No = true;
                        break;
                    }
                }
            }
            if (stack[pre - 1] == 0 && !No)
                System.out.println("yes");
            else
                System.out.println("no");
            str = scan.nextLine();
        }
        scan.close();
    }

}