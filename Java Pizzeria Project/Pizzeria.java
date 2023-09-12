/*
Trisha Andres
trishaa
Pizza Project Part 5
12/6/2022
CPSC 1061 - 003
*/

import java.util.ArrayList;
import java.util.Scanner;

public class Pizzeria {
    static Scanner scnr = new Scanner(System.in);

    public static void main(String[] args) {

        // declare and initialize variables needed
        int diameter = 0;
        int numPizzaToppings = 0;
        String name = "unknown";
        Toppings[] toppings = new Toppings[1];
        String toppingName = "unkown";
        Pizza userPizza;
        double total = 0;

        // array list, call it pizzas
        ArrayList<Pizza> pizzas = new ArrayList<Pizza>();

        // print intro
        System.out.println("Welcome to Adkins Pizzeria!");

        // ask customer what their name is and set it to new customer object
        System.out.println("What is your name?");
        String customerName = scnr.next();
        Customer customer = new Customer(customerName);

        // here are options --> print menu
        System.out.println("Here are your options of what you can do:");
        printMenu();

        // declare boolean for if user is ordering and initalize to false
        boolean isOrdering = false;

        // while user is ordering
        while (isOrdering == false) {

            // initialize variable for what the user will choose to do
            // get input from user of what they would like to do
            Character customerSelection;
            customerSelection = scnr.next().charAt(0);

            // if selection (input) is z
            while (!customerSelection.equals('c')) {
                if (customerSelection.equals('z')) {

                    // output question for name of pizza
                    System.out.println("What would you like the name of this pizza to be?");
                    // name of pizza is next string input
                    name = scnr.next();

                    // output question for pizza size (diameter)
                    System.out.println("Ok, what size would you like your pizza to be?");
                    // diameter is next int input
                    diameter = scnr.nextInt();

                    // while diameter is not in the range 6-54
                    while ((diameter < 6) || (diameter > 54)) {
                        // output to get correct pizza size in range 6-54
                        System.out.println("Please put in a correct pizza size (6-54)");
                        // diameter is the next int input
                        diameter = scnr.nextInt();
                    }

                    // output question for how many toppings
                    System.out.println("How many toppings would you like on your pizza?");
                    // pizza toppings variable is the next integer input
                    numPizzaToppings = scnr.nextInt();

                    // while input for pizza toppings is not in the range (0-6)
                    while (numPizzaToppings < 0 || numPizzaToppings > 6) {

                        // output for user to please put in an input in the correct range
                        System.out.println("Please put in a correct number of toppings (0-6)");
                        // numPizzaToppings is next input
                        numPizzaToppings = scnr.nextInt();
                    }

                    // array for toppings
                    Toppings toppings1[] = new Toppings[numPizzaToppings];

                    // for loop to go through pizza topping array
                    for (int i = 0; i < numPizzaToppings; i++) {
                        // output for what topping the user would like
                        System.out.println("What topping would you like?");
                        // input is topping name
                        toppingName = scnr.next();
                        // while topping is not a valid topping
                        while (isValidTopping(toppingName) == false) {
                            // output to get a valid topping; give selection of toppings
                            System.out.println(
                                    "Invalid Topping. Please input one of the following available toppings: Pepperoni, Bacon, Mushrooms, Chicken, Peppers, Onions");
                            // topping is next input
                            toppingName = scnr.next();
                        }
                        // temp topping
                        Toppings temp = new Toppings(toppingName);
                        // topping at i is temp
                        toppings1[i] = temp;
                    }

                    // get all stuff from above and put into userPizza
                    // pass this all into the array list pizzas
                    userPizza = new Pizza(diameter, toppings1, name);
                    pizzas.add(userPizza);

                    // output information gained from pizza
                    System.out.println("Added a pizza named " + name + " with a " + diameter + " inch diameter.");
                    // call method from Pizza.java to put all the toppings into right format
                    System.out.println(name + " has the following toppings: " + userPizza.allToppingsToString());
                    System.out.print("This pizza costs $");
                    // call method from Pizza.java to get the total cost of the pizza
                    System.out.printf("%.2f", userPizza.calculateTotalCost());
                    System.out.println(".");

                    // update total
                    total += userPizza.calculateTotalCost();

                    // what would you like to do next --> print menu
                    System.out.println("What would you like to do next?");
                    printMenu();
                    // break out of loop
                    break;
                }

                // else if user menu input is t
                else if (customerSelection.equals('t')) {

                    System.out.print("Total: $");
                    // print the customer current purchase total
                    System.out.printf("%.2f", total);
                    // new line
                    System.out.println();
                    // what would you like to do next
                    System.out.println("What would you like to do next?");
                    printMenu();
                    // break out of loop
                    break;
                }

                // if customer menu selection is r
                else if (customerSelection.equals('r')) {
                    // declare and initialize tip percent
                    double tipPercent = 0.2;
                    // declare and initalize boolean
                    boolean willUseRewardsPoints = false;

                    // if no pizza in array list or total is zero
                    // output to tell user that they can't get a receipt
                    if ((total == 0.0) || (pizzas.size() == 0)) {
                        System.out.println("You can't get a receipt if you haven't ordered anything!");
                        // what would user like to do next
                        System.out.println("What would you like to do next?");
                        printMenu();
                        // break out of loop
                        break;
                    }
                    // else get user to input a tip percent
                    else {

                        // output to see if they would like to become a rewards member
                        System.out.println("Alright, " + customerName
                                + " before we print out your receipt, would you like to become a rewards member?");
                        // answer is next string
                        String answer;
                        answer = scnr.next();

                        // while answer is not yes or no
                        // get customer to select yes or no
                        // answer is next input
                        while (!(answer.equalsIgnoreCase("Yes") || (answer.equalsIgnoreCase("No")))) {
                            System.out.println("Please select either Yes or No.");
                            answer = scnr.next();
                        }
                        // if answer is yes; sign customer up for rewards program!
                        if (answer.equalsIgnoreCase("Yes")) {
                            System.out.println("Ok, I am going to sign you up for our rewards program.");
                            // get phone number
                            System.out.println("Can I have your phone number?");
                            long phoneNumber = scnr.nextLong();
                            // get email
                            System.out.println("And can I have an email?");
                            String email = scnr.next();
                            // set customer object with name, phone number, and email
                            customer = new Customer(customerName, phoneNumber, email);
                            // does customer want to use their rewards points
                            System.out.println("Would you like to use your rewards?");
                            // set rewards to 20 points
                            double rewardsPoints = 20.0;
                            // output the points the customer has
                            System.out.println("You have " + rewardsPoints + " points");

                            // declare varialbe for if customer wants to use points
                            // answer for if they want to use points is next input
                            String usePoints;
                            usePoints = scnr.next();
                            // while answer is not yes or no get customer to input yes or no
                            // use points is next input
                            while (!(usePoints.equalsIgnoreCase("Yes") || (usePoints.equalsIgnoreCase("No")))) {
                                System.out.println("Please select either Yes or No.");
                                usePoints = scnr.next();

                            }
                            // if use points is yes
                            if (usePoints.equalsIgnoreCase("Yes")) {
                                // customer will use their rewards points (boolean is true)
                                willUseRewardsPoints = true;
                                // output to let customer know that we will be using their rewards points
                                System.out.println("Ok, we will use the rewards points from your account today.");
                            }
                        }
                    }
                    // output to get tip percent
                    System.out.println("Please input a tip percent.");
                    // tip percent is the next double that they enter
                    tipPercent = scnr.nextDouble();

                    // while tip percent if out of range
                    // get user to input tip percent in range
                    // tip percent is next double input
                    while ((tipPercent < 0) || tipPercent > 100) {
                        System.out.println("Invalid tip percent. Please input a tip percent between 0 and 100.");
                        tipPercent = scnr.nextDouble();
                    }

                    // make a new object for the receipt
                    Receipt newRec = new Receipt(pizzas, tipPercent, customer, willUseRewardsPoints);

                    // call methods from Receipt.java
                    // gets pizza info for receipt
                    // gets ending calculations for receipt
                    // output receipt
                    newRec.pizzaInformation();
                    newRec.addEndingCalculations();
                    System.out.print(newRec.getReceiptStringToPrint());

                    // restart and break out of loop
                    main(args);
                    break;
                }
                // else if user input is d
                else if (customerSelection.equals('d')) {

                    // if total is zero or if there is no pizza in the array list
                    // tell user they cannot select this menu option
                    if ((total == 0.0) || (pizzas.size() == 0)) {
                        System.out.println("You can not select this menu option until you add a pizza.");
                        // what would user like to do next
                        System.out.println("What would you like to do next?");
                        printMenu();
                        // break out of loop
                        break;
                    }
                    // if there is a pizza in array list or the total is not zero
                    else {
                        // what pizza would user like to delete
                        // give options
                        System.out.println("Which pizza would you like to delete?");
                        System.out.println("Here is the list of pizzas that are available:");

                        // declare and initialize tippercent to make a new receipt object
                        double tipPercent = 0.0;
                        // new receipt object
                        Receipt newestReceipt = new Receipt(pizzas, tipPercent, null, isOrdering);
                        // only print out pizza information for this object
                        // this gives user option of pizzas
                        System.out.println(newestReceipt.pizzaInformation());
                        // get user to select what pizza to delete
                        System.out.println("Please select which number pizza you would like to delete:");

                        // declare int variable for the deleted pizza
                        int deletedPizza;

                        // the deleted pizza is the next input
                        deletedPizza = scnr.nextInt();
                        // declare and initalize int pizzanumber to the size of pizzas
                        int pizzaNumber = pizzas.size();

                        // if the selection of the deleted pizza is out of the range
                        // output that user can only choose pizza in the range
                        // get next input for the pizza the user would like to delete
                        while ((deletedPizza <= 0) || (deletedPizza > pizzaNumber)) {
                            System.out.println("You can only delete pizzas numbered 1 to " + pizzaNumber);
                            deletedPizza = scnr.nextInt();
                        }

                        // remove the pizza that user wants to deleted
                        pizzas.remove(deletedPizza - 1);

                        // output the pizza(s) the user has now
                        System.out.println("Here is your list of pizzas now:");
                        System.out.print(newestReceipt.pizzaInformation());

                    }
                    // what would user like to do next
                    System.out.println("What would you like to do next?");
                    printMenu();
                    // break out of loop
                    break;
                } else if (customerSelection.equals('q')) {
                    // customer left
                    main(args);
                    break;
                }
                // else user menu option input is not valid
                // output to obtain valid menu option
                else {
                    System.out.println("Please input a valid menu option:");
                    // break out of loop
                    break;
                }
            }

            // while the menu option inputted is c
            while (customerSelection.equals('c')) {
                // user is not ordering anymore / quit
                isOrdering = true;
                // break out of loop
                break;
            }
        }

    }

    // runs through if topping name entered is a valid topping
    private static boolean isValidTopping(String toppingName) {
        // create and initialize boolean to false
        boolean isValidTopping = false;

        // if topping name is right then it is a valid topping
        if ((toppingName.equalsIgnoreCase("Pepperoni")) || (toppingName.equalsIgnoreCase("Onions"))
                || (toppingName.equalsIgnoreCase("Peppers"))
                || (toppingName.equalsIgnoreCase("Bacon")) || (toppingName.equalsIgnoreCase("Chicken"))
                || (toppingName.equalsIgnoreCase("Mushrooms"))) {
            isValidTopping = true;
        }
        // else not a valid topping and boolean is false
        else {
            isValidTopping = false;

        }
        // return is valid topping
        return isValidTopping;
    }

    private static String printMenu() {
        // outputs for menu and options
        System.out.println("MENU");
        System.out.println("z - Add a Pizza");
        System.out.println("t - Print the total");
        System.out.println("r - Print the Receipt");
        System.out.println("d - Delete a pizza that was ordered");
        System.out.println("q - Quit");
        System.out.println("c - Close the pizzeria for the day");

        // output to get user to make a selection
        System.out.println("Please make a selection:");
        // returns nothing
        return null;
    }
}