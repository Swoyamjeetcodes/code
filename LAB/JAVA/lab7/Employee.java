package General;

public class Employee {
    public String empId;
    private String empName;
    private double basic;

    public Employee(String empId, String empName, double basic) {
        this.empId = empId;
        this.empName = empName;
        this.basic = basic;
    }

    public double earnings() {
        double da = 0.8 * basic;
        double hra = 0.15 * basic;
        return basic + da + hra;
    }

    public String getEmpName() {
        return empName;
    }
}