class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int id_list_len = id_list.length;
        int[] answer = new int[id_list_len];
        int[][] visit = new int[id_list_len][id_list_len];
        int[] sum = new int[id_list_len];
        String[] str;
        int one = 0, two = 0;
        for(String rep : report) {
            str = rep.split(" ");    
            for(int i = 0; i < id_list_len; i++) {
                if(str[0].equals(id_list[i])) {
                    one = i;
                }
                if(str[1].equals(id_list[i])) {
                    two = i;
                }
            }
            if(visit[one][two] != 1) {
                visit[one][two] = 1;
                sum[two]++;
            }
        }
        
        for(int i = 0; i < id_list_len; i++) {
            if(sum[i] >= k) {
                for(int j = 0; j < id_list_len; j++) {
                    if(visit[j][i] == 1) {
                        answer[j]++;
                    }
                }
            }
        }

        return answer;
    }
}