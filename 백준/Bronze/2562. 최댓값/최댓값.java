import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int num;
        int result = 0;
        int index = 0;
        for(int i = 0; i < 9; i++) {
            num = scan.nextInt();
            if(result < num) {
                result = num; 
                index = i + 1;
            }
        }
        System.out.println(result + "\n" + index);
        scan.close();
    }
}