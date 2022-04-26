class Solution {
    public String solution(String number, int k) {
        char[] array = number.toCharArray();
        char[] stack = new char[1000001];
        StringBuilder sb = new StringBuilder();
        int back = 0;

        for(int i = 0; i < array.length; i++) {
            while(back != 0 && k != 0 && stack[back - 1] < array[i]) {
                k--;
                back--;
            }

            stack[back++] = array[i];
        }
    
        for(int i = 0; i < back - k; i++) {
            sb.append(stack[i]);
        }

        return sb.toString();
    }
}