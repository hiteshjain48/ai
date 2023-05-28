import java.util.Arrays;
public class First {
    void first_fit(int[] blockSize, int m, int[] processSize, int n){
        int[] allocation = new int[n];
        Arrays.fill(allocation, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(blockSize[j]>blockSize[i]){
                    blockSize[j] -= processSize[i];
                    allocation[i] = j;
                    break;
                }
            }
        }
        System.out.println("Process No." + "\t\tProcess Size" + "\t\tBlock No.");
        for (int i = 0; i < n; i++) {
            System.out.println(" " + (i+1) + "\t\t" + processSize[i]);
            if(allocation[i] != -1){
                System.out.println(allocation[i]);
            }
            else
                System.out.println("Not Allocated");
            System.out.println();
        }
    }
}
