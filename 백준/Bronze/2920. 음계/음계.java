import java.util.Scanner;

import javax.swing.text.StyledEditorKit.BoldAction;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n;
        boolean asc = true;
        boolean des = true;
        for (int i = 0; i < 8; i++) {
            n = scan.nextInt();
            if (n != i + 1)
                asc = false;
            if (n != 8 - i)
                des = false;
            if (!asc && !des) {
                System.out.println("mixed");
                scan.close();
                return;
            }
        }
        if (asc)
            System.out.println("ascending");
        else
            System.out.println("descending");
        scan.close();
    }
}