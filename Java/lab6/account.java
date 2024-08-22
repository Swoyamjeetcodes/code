import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Person[] persons = new Person[3];

        for (int i = 0; i < persons.length; i++) {
            System.out.println("Enter details for Person " + (i+1));
            persons[i] = new Person();
            persons[i].input();
        }

        System.out.println("\nDetails of Persons:");
        for (int i = 0; i < persons.length; i++) {
            System.out.println("\nPerson " + (i+1) + " details:");
            persons[i].disp();
        }
    }
}
class Account {
    int acc_no;
    double balance;

    void input() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter account number: ");
        acc_no = scanner.nextInt();
        System.out.print("Enter balance: ");
        balance = scanner.nextDouble();
    }

    void disp() {
        System.out.println("Account Number: " + acc_no);
        System.out.println("Balance: " + balance);
    }
}

class Person extends Account {
    String name;
    String aadhar_no;

    void input() {
        super.input();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter name: ");
        name = scanner.nextLine();
        System.out.print("Enter Aadhar number: ");
        aadhar_no = scanner.nextLine();
    }

    void disp() {
        super.disp();
        System.out.println("Name: " + name);
        System.out.println("Aadhar Number: " + aadhar_no);
    }
}

