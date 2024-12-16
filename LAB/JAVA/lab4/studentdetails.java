import java.util.Scanner;
public class Studentdetails {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();

       
        Student[] students = new Student[n];

        
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Student " + (i + 1) + ":");
            System.out.print("Roll Number: ");
            int roll = scanner.nextInt();
            System.out.print("Name: ");
            String name = scanner.next(); 
            System.out.print("CGPA: ");
            double cgpa = scanner.nextDouble();

            students[i] = new Student(roll, name, cgpa);
        }

       
        System.out.println("\nDetails of Students:");
        for (Student student : students) {
            System.out.println("Roll: " + student.roll + ", Name: " + student.name + ", CGPA: " + student.cgpa);
        }

       
        double lowestCgpa = students[0].cgpa;
        String lowestCgpaStudentName = students[0].name;

        for (int i = 1; i < n; i++) {
            if (students[i].cgpa < lowestCgpa) {
                lowestCgpa = students[i].cgpa;
                lowestCgpaStudentName = students[i].name;
            }
        }

        System.out.println("\nStudent with the lowest CGPA: " + lowestCgpaStudentName);

        scanner.close();
    }
}
class Student 
{
    int roll;
    String name;
    double cgpa;

    public Student(int roll, String name, double cgpa) {
        this.roll = roll;
        this.name = name;
        this.cgpa = cgpa;
    }
}