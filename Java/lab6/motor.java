
public class Main {
    public static void main(String[] args) {
        WashingMachine washingMachine = new WashingMachine();
        System.out.println("Capacity of the motor in the washing machine: " + washingMachine.capacity);
    }
}
interface Motor {
    int capacity = 10; // Interface data member

    void run();
    void consume();
}

class WashingMachine implements Motor {
    @Override
    public void run() {
        System.out.println("Washing machine is running.");
    }

    @Override
    public void consume() {
        System.out.println("Washing machine is consuming power.");
    }
}

