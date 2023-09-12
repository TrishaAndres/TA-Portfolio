/*
Trisha Andres
trishaa
Pizza Project Part 5
12/6/2022
CPSC 1061 - 003
*/

import java.util.ArrayList;

public class Receipt {

    // declare variables
    private Customer customer; //Added
    private ArrayList<Pizza> pizzas;
    private double total;
    private String receiptString;
    private double tipPercent;
    private boolean willUseRewardsPoints;
    private double pizzaTotal;
    private double rewardsPoints;
    private double rewardsTotal;

    // constant
    final double salesTaxRate = 0.06;

    // constructor to intialize variables
    Receipt(ArrayList<Pizza> pizzas, double tipPercent, Customer customer, boolean willUseRewardsPoints) {
        this.pizzas = pizzas;
        this.tipPercent = tipPercent;
        total = 0.0;
        pizzaTotal = 0.0;
        rewardsTotal = 0.0;
        this.receiptString = "";
        this.customer = customer;
        this.willUseRewardsPoints = willUseRewardsPoints;
    }

    // method to get pizza information
    public String pizzaInformation(){
        // output header for receipt
        System.out.println("=======RECEIPT========");
        // iterate through pizzas in the array list
        for (int i = 0; i < pizzas.size(); i++) {
            // output pizza information
            // name, diameter, toppings, cost
            this.receiptString += ("Pizza " + (i + 1) + ": " + pizzas.get(i).getDiameter() + " inch diameter");
            //new line
            this.receiptString += (pizzas.get(i).getName() + " has the toppings " + pizzas.get(i).allToppingsToString());
            //new line 
            this.receiptString += ("Cost: $");
            this.receiptString += (pizzas.get(i).calculateTotalCost());
            //new line 
            System.out.println();

            // update total cost of pizza(s)
            pizzaTotal += pizzas.get(i).calculateTotalCost();
        }
        // return string
        return this.receiptString;
    }
    
    // method for ending calculations on receipt
    public String addEndingCalculations(){
        // output to separate receipt info
        System.out.println("======================");
        // make sure tip is in decimal form and not percent form
        tipPercent = tipPercent / 100.0;

        // TOTALl output with two decimal spaces
        System.out.print("Total: $");
        System.out.printf("%.2f", pizzaTotal);
        System.out.println();

        // calculation for tax using constant
        double tax = salesTaxRate * pizzaTotal;

        // TAX; output with two decimal spaces
        System.out.print("Tax: $");
        System.out.printf("%.2f", tax);
        System.out.println();

        // calculation for tip
        double tip = tipPercent * (pizzaTotal + tax);

        // TIP; output with two decimal places
        System.out.print("Tip: $");
        System.out.printf("%.2f", tip);
        System.out.println();

        total = (tip + tax + pizzaTotal);

        // REWARDS POINTS
        double rewardsToBeAdded = 0;
        //Variable that stores the amount of rewardsPoints that the customer will be using
        double rewardsPointsUsed = 0;
        //Variable that stores the initial rewardsPoints of the customer
        double customerRewardsPoints = customer.getRewardsPoints();
        //The customer will only be able to use rewards points if they are a rewards member
        if (customer.isRewardsMember()) {
            rewardsToBeAdded = (.2 * total);
            if (willUseRewardsPoints == true) {
                if (total >= customerRewardsPoints) {
                    rewardsPointsUsed = customerRewardsPoints;
                }
                else {
                    rewardsPointsUsed = total;
                }
                total -= rewardsPointsUsed;
                customer.useRewardsPoints(rewardsPointsUsed);
            }
            customer.addRewardsPoints(rewardsToBeAdded);
        }

        //output rewards points that were used 
        System.out.print("Rewards Points Used: ");
        System.out.printf("%.2f", rewardsPointsUsed);
        System.out.println();
        
        

        // calculation for final total cost of all pizza(s)
        // FINAL TOTAL; output with two decimal places
        System.out.print("Final Total: $");
        System.out.printf("%.2f", total);
        System.out.println();

   
        // output separator
        System.out.println("======================");

        //calculation for rewards points
        System.out.println("Today's Transaction for " + customer.getName() + ": ");
        
        System.out.print("Rewards Points Added: "); 
        System.out.printf("%.2f", rewardsToBeAdded);
        System.out.println();
        
        System.out.print("Rewards Points Remaining: " );
        System.out.printf("%.2f", customer.getRewardsPoints());
        System.out.println();
        

        System.out.println("======================");

        // return string
        return this.receiptString;

    }

    public String getReceiptStringToPrint() {
        // return string
        return this.receiptString;
    }
    
}