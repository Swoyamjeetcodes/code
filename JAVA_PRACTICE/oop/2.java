class Main {
  public static void main(String[] args) {

    try {

      // code that generate exception
      int divideByZero = 5 / 1;
      System.out.println("Rest of code in try block");
    }
    
    catch (ArithmeticException c) {
      System.out.println("ArithmeticException => " + c.getMessage());
    }
  }
}