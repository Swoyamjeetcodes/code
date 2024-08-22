public class Main {
    public static void main(String[] args) {
        Apple apple = new Apple();
        Apple banana = new Banana();
        Apple cherry = new Cherry();

        apple.show();
        banana.show();
        cherry.show();
    }
}
class Apple {
    void show() {
        System.out.println("This is the show() method of Apple class");
    }
}

class Banana extends Apple {
    void show() {
        System.out.println("This is the show() method of Banana class");
    }
}

class Cherry extends Apple {
    void show() {
        System.out.println("This is the show() method of Cherry class");
    }
}

