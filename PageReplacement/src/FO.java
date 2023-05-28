import java.util.Arrays;
import java.util.Scanner;

public class FO {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int frames = 0;
        int refLen = 0;
        int hit = 0;
        int fault = 0;
        int pointer = 0;
        System.out.println("Frames: ");
        frames = sc.nextInt();
        System.out.println("String len: ");
        refLen = sc.nextInt();
        int[] refString = new int[refLen];
        int[] buffer = new int[frames];
        Arrays.fill(buffer, -1);
        for (int i = 0; i < refLen; i++) {
            refString[i] = sc.nextInt();
        }
        for (int i = 0; i < refLen; i++) {
            int search = -1;
            for (int j = 0; j < frames; j++) {
                if (buffer[j]==refString[i]){
                    search = j;
                    hit++;
                    break;
                }
            }
            if (search == -1){
                buffer[pointer] = refString[i];
                fault++;
                pointer++;
                if (pointer == frames){
                    pointer = 0;
                }
            }
        }
        System.out.println("Hits: "+hit);
        System.out.println("Faults: "+fault);
    }
}