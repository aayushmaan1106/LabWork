// Set 2 - Problem 2: Bank Account with Constructor Overloading
public class c2 {
    public static void main(String[] args) {
        BankAccount a1 = new BankAccount(1001, "Aamir");          // zero balance
        BankAccount a2 = new BankAccount(1002, "Sara", 5000);     // opening balance

        a1.deposit(2000);
        a2.withdraw(1500);

        // Invalid transactions are rejected
        a1.withdraw(10000);   // exceeds balance
        a2.deposit(-100);     // negative amount
        a2.withdraw(-50);     // negative amount

        System.out.println("\n--- Updated balances ---");
        a1.displayBalance();
        a2.displayBalance();
    }
}

class BankAccount {
    private final int accountNumber;
    private final String holderName;
    private double balance;            // private: no direct access

    public BankAccount(int accountNumber, String holderName) {
        this(accountNumber, holderName, 0);
    }

    public BankAccount(int accountNumber, String holderName, double openingBalance) {
        if (openingBalance < 0) {
            throw new IllegalArgumentException("Opening balance cannot be negative");
        }
        this.accountNumber = accountNumber;
        this.holderName = holderName;
        this.balance = openingBalance;
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("Deposit rejected: amount must be positive (" + amount + ")");
            return;
        }
        balance += amount;
        System.out.println("Deposited " + amount + " into account " + accountNumber);
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Withdrawal rejected: amount must be positive (" + amount + ")");
        } else if (amount > balance) {
            System.out.println("Withdrawal rejected: insufficient balance in account " + accountNumber);
        } else {
            balance -= amount;
            System.out.println("Withdrew " + amount + " from account " + accountNumber);
        }
    }

    public void displayBalance() {
        System.out.println("Account " + accountNumber + " (" + holderName + ") balance: " + balance);
    }
}
