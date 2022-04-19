import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        String str = scan.nextLine();
        String RvsStr;
        boolean T = true;
        while (!str.equals("0")) {

            RvsStr = "";
            for (int i = 0; i < str.length(); i++) {
                RvsStr = RvsStr + str.charAt(str.length() - 1 - i);
            }
            if (RvsStr.equals(str)) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
            str = scan.nextLine();
        }

        scan.close();
    }
}