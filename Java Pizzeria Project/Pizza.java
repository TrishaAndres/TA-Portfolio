/*
Trisha Andres
trishaa
Pizza Project Part 5
12/6/2022
CPSC 1061 - 003
*/

public class Pizza {
    // declare variables needed
    private int diameter;
    private Toppings[] toppings;
    private String name;
    private double area;

    // constants needed
    final double cheeseCostPerInch = .028;
    final double sauceCostPerInch = .039;
    final double doughCostPerInch = .008;

    // default constructor to define diameter and name
    public Pizza() {
        diameter = 0;
        name = "unknown";
    }

    // constructor to initialize using 'this.'
    public Pizza(int diameter, Toppings[] toppings, String name) {
        this.diameter = diameter;
        this.name = name;
        this.toppings = toppings;
        this.area = calculateArea(diameter);
    }

    // method to calculate total cost of pizza
    public double calculateTotalCost() {
        // declare and initialize total cost at zero
        double totalCost = 0.00;
        // totalcost is calculated by adding base cost and toppings cost together
        totalCost = calculateBaseCost() + calculateToppingsCost();
        // return total cost
        return totalCost;
    }

    // method to calculate toppings cost
    private double calculateToppingsCost() {
        // get cost of toppings listed
        // calculate
        double toppingCost = 0;
        // for loop to go through toppings
        // adds cost per inch multiplied by the area of the pizza
        // adds this cost to the total toppings cost
        for (int i = 0; i < toppings.length; i++) {
            toppingCost += ((toppings[i].getCostPerInch()) * area);
        }
        // return toppings cots
        return toppingCost;
    }

    // method to calculate base cost
    private double calculateBaseCost() {
        // get area from calculation method above with the inputted diameter from
        // Pizzeria file
        calculateArea(diameter);
        // multiply pizza area by cheesecostperinch, saucecostperinch, and
        // doughcostperinch and add all together
        double baseCost = ((calculateArea(diameter) * cheeseCostPerInch) + (calculateArea(diameter) * sauceCostPerInch)
                + (calculateArea(diameter) * doughCostPerInch));
        // return base cost
        return baseCost;
    }

    // method to get toppings on pizza & return it
    public Toppings[] getToppings() {
        return toppings;
    }

    // method to get name of pizza & return it
    public String getName() {
        return name;
    }

    // method to get diameter & return it
    public int getDiameter() {
        return this.diameter;
    }

    // method to calculate area
    private double calculateArea(int diameter) {
        // calculation for the area of the pizza
        area = Math.PI * Math.pow(((double) diameter / 2), 2);
        // return area
        return area;
    }

    // method to get toppings to string
    public String allToppingsToString() {
        // initalize total
        String total = "";
        // if nothing then output NONE
        if (toppings.length == 0) {
            return "NONE";
        }
        // for loop to go through length of toppings
        for (int i = 0; i < toppings.length - 1; i++) {
            // get toppings to all lowercase
            // comma and spcae between each toppings
            total += toppings[i].getName().toLowerCase() + ", ";

        }
        // last variable does not need space and comma
        total += toppings[toppings.length - 1].getName().toLowerCase() + ".";
        // return total
        return total;
    }

}