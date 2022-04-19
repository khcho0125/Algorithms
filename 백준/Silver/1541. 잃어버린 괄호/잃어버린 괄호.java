import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        String[] stack = new String[25];
        int[] arr = new int[50];
        int pre = 0;
        for (String s : str.split("\\+|-")) {
            arr[pre] = Integer.parseInt(s);
            pre++;
        }
        int result = 0;
        pre = 0;
        for (String s : str.split("")) {
            if (s.equals("-")) {
                stack[pre] = "-";
                pre++;
            } else if (s.equals("+")) {
                stack[pre] = "+";
                pre++;
            }
        }
        while (pre != 0) {
            if (stack[pre - 1].equals("-")) {
                result -= arr[pre];
            } else {
                arr[pre - 1] += arr[pre];
            }
            pre--;
        }
        result += arr[0];
        System.out.println(result);
    }
}