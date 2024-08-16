using System;

class Calculator
{
    static void Main()
    {
        double operand1, operand2, result = 0;
        bool useResult = false;

        do
        {
            Console.WriteLine("\nChoose an option:");
            Console.WriteLine("1. Add");
            Console.WriteLine("2. Subtract");
            Console.WriteLine("3. Multiply");
            Console.WriteLine("4. Divide");
            Console.WriteLine("5. Exit\n");

            Console.Write("Enter your choice (1-5): ");
            if (!int.TryParse(Console.ReadLine(), out int choice) || choice < 1 || choice > 5)
            {
                Console.WriteLine("Invalid choice. Please enter a number between 1 and 5.");
                continue;
            }

            if (choice == 5)
            {
                Console.WriteLine("Exiting the program. Goodbye!");
                Environment.Exit(0);
            }

            if (!useResult)
            {
                Console.Write("Enter operand 1: ");
                while (!double.TryParse(Console.ReadLine(), out operand1))
                {
                    Console.WriteLine("Invalid input. Please enter a valid number.");
                    Console.Write("Enter operand 1: ");
                }

                Console.Write("Enter operand 2: ");
                while (!double.TryParse(Console.ReadLine(), out operand2))
                {
                    Console.WriteLine("Invalid input. Please enter a valid number.");
                    Console.Write("Enter operand 2: ");
                }
            }
            else
            {
                operand1 = result;
                Console.Write($"Enter operand 2 (previous result: {FormatResult(result)}): ");
                while (!double.TryParse(Console.ReadLine(), out operand2))
                {
                    Console.WriteLine("Invalid input. Please enter a valid number.");
                    Console.Write($"Enter operand 2 (previous result: {FormatResult(result)}): ");
                }
            }

            switch (choice)
            {
                case 1:
                    result = operand1 + operand2;
                    break;
                case 2:
                    result = operand1 - operand2;
                    break;
                case 3:
                    result = operand1 * operand2;
                    break;
                case 4:
                    if (operand2 != 0)
                        result = operand1 / operand2;
                    else
                    {
                        Console.WriteLine("Cannot divide by zero. Please enter a non-zero divisor.");
                        continue;
                    }
                    break;
            }

            useResult = true;
            Console.WriteLine($"Result: {FormatResult(result)}");
        } while (true);
    }

    static string FormatResult(double result)
    {
        return result % 1 == 0 ? result.ToString("N0") : result.ToString("N2");
    }
}