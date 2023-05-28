import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        FF first = new FF();
        NextFit next = new NextFit();
        WorstFit worst = new WorstFit();
        BestFit best = new BestFit();
        Scanner scan = new Scanner(System.in);
        int choice;
        System.out.println();
        System.out.println("Enter the number of Blocks: ");
        int m = scan.nextInt();
        System.out.println("Enter the number of Processes:");
        int n = scan.nextInt();
        int[] blockSize = new int[m];
        int[] processSize = new int[n];
        System.out.println("Enter the Size of all the blocks:");
        for (int i = 0; i<m; i++){
            blockSize[i] = scan.nextInt();
        }
        System.out.println("Enter the size of all processes:");
        for (int i = 0; i<n; i++){
            processSize[i] = scan.nextInt();
        }
        while(true){
            System.out.println();
            System.out.println("Menu");
            System.out.println("1. First Fit ");
            System.out.println("2. Next Fit");
            System.out.println("3. Worst Fit");
            System.out.println("4. Best Fit");
            System.out.println("5. exit");
            System.out.println("Select the algorithm you want to implement: ");
            choice = scan.nextInt();
            switch (choice) {
                case 1 -> {
                    System.out.println("First Fit Output");
                    first.first(blockSize, m, processSize, n);
                }
                case 2 -> {
                    System.out.println("Next Fit Output");
                    next.next_fit(blockSize, m, processSize, n);
                }
                case 3 -> {
                    System.out.println("Worst Fit Output");
                    worst.worstFit(blockSize, m, processSize, n);
                }
                case 4 -> {
                    System.out.println("Best Fit Output");
                    best.bestFit(blockSize, m, processSize, n);
                }
                case 5 -> {
                    System.out.println("Exiting the code...");
                    return;
                }
                default -> System.out.println("Invalid option");
            }
        }
    }
}
