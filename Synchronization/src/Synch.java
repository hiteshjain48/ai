import java.util.LinkedList;
import java.util.concurrent.ThreadLocalRandom;

public class Synch {
    public static void main(String[] args) throws InterruptedException {
        final Pc pc = new Pc();
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.produce();
                }
                catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        });
        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    pc.consume();
                }
                catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        });
        t1.start();
        t2.start();
        t1.join();
        t2.join();
    }
    public static class Pc{
        LinkedList<Integer> list = new LinkedList<>();
        int capacity = 2;
        public void produce() throws InterruptedException {
            int value= 0;
            while (true){
                synchronized (this){
                    if (list.size()==capacity){
                        wait();
                    }
                    System.out.println("Producer Produced: " + value);
                    list.add(value++);
                    notify();
                    Thread.sleep(1000);
                }
            }
        }
        public void consume() throws InterruptedException {
            while (true){
                synchronized (this){
                    if (list.size()==0)
                        wait();
                    int val = list.removeFirst();
                    System.out.println("Consumer Consumes: "+ val);
                    notify();
                    Thread.sleep(1000);
                }
            }
        }
    }
}
