/*
Trisha Andres
trishaa
Pizza Project Part 5
12/6/2022
CPSC 1061 - 003
*/

public class Customer {
    // declare private variables needed
    private String name;
    private boolean isRewardsMember;
    private double rewardsPoints;
    private long phoneNumber;
    private String email;

    // constructor for customer with just name given
    public Customer(String customerName) {
        // this name is customer name
        this.name = customerName;
        // this rewards member is false
        this.isRewardsMember = false;
        // this rewards points equals 0
        this.rewardsPoints = 0.0;
    }

    // constructor for customer with name, phone number, and email
    public Customer(String customerName, long phoneNumber, String email) {
        // this name is customer name
        this.name = customerName;
        // this phone number is phone number
        this.phoneNumber = phoneNumber;
        // this email is email
        this.email = email;

        // rewards member boolean is true
        this.isRewardsMember = true;
        // rewards points are initialized at 20
        this.rewardsPoints = 20.0;
    }

    // public method for is rewards member
    // returns is rewards member
    public boolean isRewardsMember() {
        return this.isRewardsMember;
    }

    // public method to get rewards points
    // returns rewards points
    public double getRewardsPoints() {
        return rewardsPoints;
    }

    // public method for name
    // returns name
    public String getName() {
        return name;
    }

    // accessors for fields in this class

    // adds rewards points
    public void addRewardsPoints(double points) {
        this.rewardsPoints += points;
    }

    // for used rewards points
    public void useRewardsPoints(double points) {
        this.rewardsPoints -= points;
    }
}
