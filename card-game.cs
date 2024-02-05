using System;

public class CardGame
{
    private static Random random = new Random();
    private static Tuple<string, string>[] deck;

public static void Main(string[] args)
    {
        int choice;
        
        do
        {
            Console.WriteLine("\nChoose an option:");
            Console.WriteLine("1. Create");
            Console.WriteLine("2. Shuffle");
            Console.WriteLine("3. Deal");
            Console.WriteLine("4. Display");
            Console.WriteLine("5. Quit");

            Console.Write("Enter your choice (1-5): ");
            if (int.TryParse(Console.ReadLine(), out choice))
            {
                switch (choice)
                {
                    case 1:
                        Create();
                        break;
                    case 2:
                        Shuffle();
                        break;
                    case 3:
                        Console.Write("How many cards do you want to deal? ");
                        int numberOfCardsToDeal = int.Parse(Console.ReadLine());
                        Deal(numberOfCardsToDeal);
                        break;
                    case 4:
                        Display();
                        break;
                    case 5:
                        Console.WriteLine("Exiting the program. Goodbye!");
                        break;
                    default:
                        Console.WriteLine("Invalid choice. Please enter a number between 1 and 5.");
                        break;
                }
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a number.");
            }
        } while (choice != 5);
    }

    public static void Create()
    {
        deck = new Tuple<string, string>[52];
        string[] suits = { "Clubs", "Diamonds", "Hearts", "Spades" };
        string[] ranks = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

        int index = 0;
        foreach (var suit in suits)
        {
            foreach (var rank in ranks)
            {
                deck[index] = Tuple.Create(suit, rank);
                index++;
            }
        }
        Console.WriteLine("New deck created.");
    }

    public static void Shuffle()
    {
        int n = deck.Length;
        if(n > 0){
          for (int i = n - 1; i > 0; i--)
          {
            int j = random.Next(0, i + 1);
            Tuple<string, string> temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
          }
            Console.WriteLine("Deck shuffled.");
        }else{
            Console.WriteLine("Unable to shuffle, deck is empty.");
    }

    public static void Deal(int numberOfCards)
    {
        Console.WriteLine("Dealing {0} cards:", numberOfCards);
        
        if (numberOfCards > deck.Length)
        {
            Console.WriteLine("Not enough cards in the deck. Please enter a valid number.");
            return;
        }
    
        for (int i = 0; i < numberOfCards; i++)
        {
            Tuple<string, string> card = deck[deck.Length - 1];
            deck = ResizeArray(deck, deck.Length - 1);
            Console.WriteLine("Suit: {0}, Rank: {1}", card.Item1, card.Item2);
        }
    }

    public static void Display()
    {
        Console.WriteLine("\nRemaining cards in the deck:");
        foreach (var card in deck)
        {
            Console.WriteLine("Suit: {0}; Rank: {1}", card.Item1, card.Item2);
        }
        Console.WriteLine("Number of cards remaining: {0}\n", deck.Length);
    }

    private static Tuple<string, string>[] ResizeArray(Tuple<string, string>[] array, int newSize)
    {
        Tuple<string, string>[] newArray = new Tuple<string, string>[newSize];
        Array.Copy(array, newArray, newSize);
        return newArray;
    }
}
