import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        StringBuilder result = new StringBuilder();
        int[] arr = new int[n];
        int[] temp = new int[n + 1];
        int pre = 0, i;
        int index = 1;
        boolean check = false;
        for (i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
        }
        temp[0] = 0;
        for (i = 0; i < n; i++) {
            while (temp[pre] != arr[i]) {
                if (pre >= n) {
                    check = true;
                    break;
                }
                pre++;
                temp[pre] = index++;
                result.append("+\n");
            }
            if (pre != 0)
                pre--;  
            result.append("-\n");
        }
        if(!check) {
            System.out.println(result);
        } else {
            System.out.println("NO");
        }
        scan.close();
    }
}