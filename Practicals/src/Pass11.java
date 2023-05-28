import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

import static java.lang.Integer.parseInt;

public class Pass11 {
    public static void main(String[] args) throws Exception{
        FileReader file = new FileReader("C:\\Users\\Hitesh\\Desktop\\College\\TE\\SPOS\\Practicals\\input\\input.txt");
        BufferedReader bf = new BufferedReader(file);
        String line = null;
        int line_count = 0;
        int LC = 0;
        int symTabLine = 0;
        final int MAX = 100;
        String[][] SymTab = new String[MAX][3];
        while((line = bf.readLine())!=null){
            String[] tokens = line.split("\t");
            if (line_count==0){
                LC = Integer.parseInt(tokens[1]);
                for (int i = 0; i < tokens.length; i++) {
                    System.out.print(tokens[i] + "\t");
                }
                System.out.println("");
            }
            else {
                for (int i = 0; i < tokens.length; i++) {
                    System.out.print(tokens[i] + "\t");
                }
                System.out.println("");
                if (!tokens[0].equals("")){
                    SymTab[symTabLine][0] = tokens[0];
                    SymTab[symTabLine][1] = Integer.toString(LC);
                    SymTab[symTabLine][2] = Integer.toString(1);
                    symTabLine++;
                }
                else if(tokens[1].equalsIgnoreCase("DS")||tokens[1].equalsIgnoreCase("DC")){
                    SymTab[symTabLine][0] = tokens[0];
                    SymTab[symTabLine][1] = Integer.toString(LC);
                    SymTab[symTabLine][2] = Integer.toString(1);
                    symTabLine++;
                }
            }
            LC++;
            line_count++;
        }
        System.out.println("--------Symbol Table---------");
        System.out.println("Symbol\tAddress\tLength");
        for (int i = 0; i < symTabLine; i++) {
            System.out.println(SymTab[i][0] +"\t"+ SymTab[i][1] +"\t"+SymTab[i][2]);
        }
    }
}
