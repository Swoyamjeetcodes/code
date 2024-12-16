public class CounterThread extends Thread {
    private String threadName;
    private int startValue;
    private int endValue;

    public CounterThread(String threadName, int startValue, int endValue) {
        this.threadName = threadName;
        this.startValue = startValue;
        this.endValue = endValue;
    }

    @Override
    public void run() {
        for (int i = startValue; i <= endValue; i++) {
            System.out.println(threadName + ": " + i);
            try {
                Thread.sleep(500); // Sleep for 500 milliseconds
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        // Take input from the user for thread name and range of values
        String threadName = args[0];
        int startValue = Integer.parseInt(args[1]);
        int endValue = Integer.parseInt(args[2]);

        // Create and start the thread
        CounterThread counterThread = new CounterThread(threadName, startValue, endValue);
        counterThread.start();
    }
}
