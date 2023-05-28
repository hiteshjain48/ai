import java.util.Scanner;
import java.util.Arrays;
public class FFS{
    public void execute(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of processes: ");
        int numProcess = sc.nextInt();
        Pcs[] process = new Pcs[numProcess];
        for (int i = 0; i < numProcess; i++) {
            System.out.println("Enter the arrival and burst time: ");
            int at = sc.nextInt();
            int bt = sc.nextInt();
            process[i] = new Pcs("P"+(1+i),at,bt);
        }
        Arrays.sort(process, new SortArr());
        int sum = 0;
        int avgWT =0;
        int avgCT = 0;
        for (int i = 0; i < numProcess; i++) {
            sum = process[i].CT = sum + process[i].BT;
            process[i].TAT = process[i].CT - process[i].AT;
            process[i].WT = process[i].TAT - process[i].BT;
            avgWT = avgWT + process[i].WT;
            avgCT = avgCT + process[i].CT;
            process[i].display();
        }
        System.out.println("Average WT: "+(double)avgWT/numProcess);
        System.out.println("Average CT: "+(double)avgCT/numProcess);
    }
}