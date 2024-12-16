package Marketing;
import General.Employee;

public class Sales extends Employee {
    // Constructor
    public Sales(String empId, String empName, double basic) {
        super(empId, empName, basic);
    }

    // Method to calculate travelling allowance
    public double allowance() {
        double totalEarnings = earnings();
        return 0.05 * totalEarnings;
    }
}