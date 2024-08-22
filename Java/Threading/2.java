public class Main {
    public static void main(String[] args) {
        PrintMessage printMessage = new PrintMessage();
        Thread1 t1 = new Thread1(printMessage);
        Thread2 t2 = new Thread2(printMessage);
        t1.start();
        t2.start();
    }
}
class PrintMessage {
    // Flag to determine which thread should execute next
    private boolean flag = true;

    // Method to print the message in synchronized manner
    synchronized void printMessage(String message, boolean threadFlag) {
        // If the flag doesn't match with the threadFlag, wait
        while (flag != threadFlag) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        // Print the message
        System.out.println(message);
        // Toggle the flag to allow the other thread to execute
        flag = !flag;
        // Notify waiting threads
        notify();
    }
}

class Thread1 extends Thread {
    private PrintMessage pm;

    Thread1(PrintMessage pm) {
        this.pm = pm;
    }

    public void run() {
        pm.printMessage("I", true);
        pm.printMessage("Love", true);
        pm.printMessage("java", true);
        pm.printMessage("Very", true);
        pm.printMessage("Much", true);
    }
}

class Thread2 extends Thread {
    private PrintMessage pm;

    Thread2(PrintMessage pm) {
        this.pm = pm;
    }

    public void run() {
        pm.printMessage("I", false);
        pm.printMessage("Love", false);
        pm.printMessage("java", false);
        pm.printMessage("Very", false);
        pm.printMessage("Much", false);
    }
}

