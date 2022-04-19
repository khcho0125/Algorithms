import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder result = new StringBuilder();
        char[] str = br.readLine().toCharArray();
        char[] stack = new char[100];
        int pre = 0;
        int len = str.length;
        for (int i = 0; i < len; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                result.append(str[i]);
            } else {
                switch (str[i]) {
                    case '(':
                        stack[pre++] = str[i];
                    case '/':
                    case '*':
                        while (pre != 0 && (stack[pre - 1] == '/' || stack[pre - 1] == '*')) {
                            result.append(stack[--pre]);
                        }
                        stack[pre++] = str[i];
                        break;
                    case '+':
                    case '-':
                        while (pre != 0 && stack[pre - 1] != '(') {
                            result.append(stack[--pre]);
                        }
                        stack[pre++] = str[i];
                        break;
                    case ')':
                        while (pre != 0 && stack[--pre] != '(') {
                            result.append(stack[pre]);

                        }
                        pre--;
                        break;
                }
            }
        }
        while (pre != 0) {
            result.append(stack[--pre]);
        }
        bw.write(result + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}