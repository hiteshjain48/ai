import java.util.Comparator;

public class Pcs{
    String name;
    int AT, BT, CT, WT, TAT;

    public Pcs(String name, int AT, int BT){
        this.name = name;
        this.AT = AT;
        this.BT = BT;
        TAT = CT= WT = 0;
    }

    void display(){
        System.out.println("Name of Process: " + this.name);
        System.out.println("Arrival Time: "+ this.AT);
        System.out.println("Burst Time: " + this.BT);
        System.out.println("Completion Time: "+ this.CT);
        System.out.println("Turn Around Time: " + this.TAT);
        System.out.println("Waiting Time: " + this.WT);
    }
}
class SortArr implements Comparator<Pcs>{
    @Override
    public int compare(Pcs p1, Pcs p2){
        return p1.AT - p2.AT;
    }
}