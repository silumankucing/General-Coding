import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the Calculator");
        System.out.println("-------------------------");
        System.out.println("1. Basic Operations (+, -, *, /)");
        System.out.println("2. Factorial Operation");
        System.out.print("Choose an option : ");
        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                basicOperations(scanner);
                break;

            case 2:
                factorialOperations(scanner);
                break;

            default:
                System.out.println("Invalid choice. Please restart the program.");
        }

        scanner.close();
    }

    private static void basicOperations(Scanner scanner){

        System.out.println("Simple Calculator");
        System.out.println("------------------");

        System.out.print("Enter first number: ");
        double num1 = scanner.nextDouble();

        System.out.print("Enter operator (+, -, *, /): ");
        char operator = scanner.next().charAt(0);

        System.out.print("Enter second number: ");
        double num2 = scanner.nextDouble();

        double result;

        try {
            switch (operator) {
                case '+':
                    result = BasicOperations.add(num1, num2);
                    System.out.println("Result: " + result);
                    break;
                case '-':
                    result = BasicOperations.subtract(num1, num2);
                    System.out.println("Result: " + result);
                    break;
                case '*':
                    result = BasicOperations.multiply(num1, num2);
                    System.out.println("Result: " + result);
                    break;
                case '/':
                    result = BasicOperations.divide(num1, num2);
                    System.out.println("Result: " + result);
                    break;
                default:
                    System.out.println("Invalid operator");
            }
        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static void factorialOperations(Scanner scanner){
        System.out.println("\nFactorial Operation");
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();

        try{
            long resultRecursive = FactorialOperations.factorialRecursive(num);
            System.out.println(resultRecursive);

        }catch(IllegalArgumentException e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}
