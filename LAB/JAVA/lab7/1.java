import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Employee ID:");
        int empId = scanner.nextInt();
        scanner.nextLine(); 
        System.out.println("Enter Employee Name:");
        String empName = scanner.nextLine();
        System.out.println("Enter Department ID:");
        int deptId = scanner.nextInt();
        scanner.nextLine(); 
        System.out.println("Enter Department Name:");
        String deptName = scanner.nextLine();

        Head head = new Head(empId, empName, deptId, deptName);

        head.displayHeadDetails();

        scanner.close();
    }
}

interface Employee {
    void getDetails();
}

interface Manager extends Employee {
    void getDeptDetails();
}

class Head implements Manager {
    private int empId;
    private String empName;
    private int deptId;
    private String deptName;

    public Head(int empId, String empName, int deptId, String deptName) {
        this.empId = empId;
        this.empName = empName;
        this.deptId = deptId;
        this.deptName = deptName;
    }

    public void getDetails() {
        System.out.println("Employee ID: " + empId);
        System.out.println("Employee Name: " + empName);
    }

    public void getDeptDetails() {
        System.out.println("Department ID: " + deptId);
        System.out.println("Department Name: " + deptName);
    }

    public void displayHeadDetails() {
        System.out.println("Head Details:");
        getDetails();
        getDeptDetails();
    }
}

