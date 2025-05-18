import java.util.*;

public class Demo {
    public static void main(String[] args) {
        // Using List interface with ArrayList
        List<String> names = new ArrayList<>();
        names.add("Alice");
        names.add("Bob");

        System.out.println("Using ArrayList: " + names);

        // Now swap ArrayList with LinkedList without changing rest of code
        names = new LinkedList<>();
        names.add("Charlie");
        names.add("David");

        System.out.println("Using LinkedList: " + names);
        names = ArrayList<>();
        System.out.println(names);
    }
}
