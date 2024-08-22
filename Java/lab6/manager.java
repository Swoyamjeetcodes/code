import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter basic salary for Substaff: ");
        double basicSalary = scanner.nextDouble();

        
        Substaff substaff = new Substaff();

                System.out.println("\nDetails for Substaff:");
        double earnings = substaff.earnings(basicSalary);
        double deductions = substaff.deductions(basicSalary);
        double bonus = substaff.bonus(basicSalary);

        
        System.out.println("Earnings: " + earnings);
        System.out.println("Deductions: " + deductions);
        System.out.println("Bonus: " + bonus);
    }
}


interface EmployeeInterface 
{
    double earnings(double basic);
    double deductions(double basic);
    double bonus(double basic);
}


class Manager implements EmployeeInterface {
    @Override
    public double earnings(double basic) {
        
        return basic + 0.8 * basic + 0.15 * basic;
    }

    @Override
    public double deductions(double basic) {
        
        return 0.12 * basic;
    }

    
    @Override
    public double bonus(double basic) {
        throw new UnsupportedOperationException("Manager does not have a bonus implementation");
    }
}


class Substaff extends Manager {
    @Override
    public double bonus(double basic) {
        
        return 0.5 * basic;
    }
}