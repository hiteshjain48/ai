import java.util.Arrays;

public class FF {
    void first(int[] blockSize, int m, int[] processSize, int n){
        int[] track = new int[n];
        Arrays.fill(track,-1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(blockSize[j]>=processSize[i]) {
                    blockSize[j] -= processSize[i];
                    track[i] = j+1;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println("process No." + i+1);
            System.out.println("Process Size" + processSize[i]);

            if (track[i] == -1){
                System.out.println("block" + "NOt allocated");
            }
            else{
                System.out.println("block " + track[i]);
            }
        }
    }
}
