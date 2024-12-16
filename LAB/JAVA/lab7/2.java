import Marketing.Sales;

public class main {
    public static void main(String[] args) {
        Sales salesPerson = new Sales("S001", "Alice", 5000);

        System.out.println("Employee ID: " + salesPerson.empId);
        System.out.println("Total Earnings: $" + salesPerson.earnings());
        System.out.println("Travelling Allowance: $" + salesPerson.allowance());
    }
}