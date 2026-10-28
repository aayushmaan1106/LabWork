// Set 3 - Problem 5: Banking System with Method Overriding
public class c5 {
    public static void main(String[] args) {
        Account[] accounts = {
            new SavingsAccount(1001, 10000),     // minimum balance Rs.1000
            new CurrentAccount(2001, 2000)       // overdraft limit Rs.5000
        };

        for (Account acc : accounts) {
            System.out.println("=== " + acc.getClass().getSimpleName() + " " + acc.getAccountNumber() + " ===");
            acc.deposit(2000);
            acc.deposit(500, "Cash deposit at branch");   // overloaded deposit
            acc.deposit(-100);                             // rejected
            acc.withdraw(9000);
            acc.withdraw(5000);
            acc.withdraw(-10);                             // rejected
            System.out.printf("Interest: %.2f%n", acc.calculateInterest());
            System.out.printf("Final balance: %.2f%n%n", acc.getBalance());
        }
    }
}

class Account {
    private final int accountNumber;
    protected double balance;

    Account(int accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }

    void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("Deposit rejected: invalid amount " + amount);
            return;
        }
        balance += amount;
        System.out.println("Deposited " + amount);
    }

    // Overloaded: amount with a transaction description
    void deposit(double amount, String description) {
        System.out.println("Transaction note: " + description);
        deposit(amount);
    }

    boolean withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            System.out.println("Withdrawal rejected: " + amount);
            return false;
        }
        balance -= amount;
        System.out.println("Withdrew " + amount);
        return true;
    }

    double calculateInterest() {
        return 0;
    }
}

class SavingsAccount extends Account {
    private static final double MIN_BALANCE = 1000;
    private static final double INTEREST_RATE = 0.04;   // 4% per year

    SavingsAccount(int accountNumber, double balance) {
        super(accountNumber, balance);
    }

    @Override
    boolean withdraw(double amount) {
        if (amount <= 0 || balance - amount < MIN_BALANCE) {
            System.out.println("Withdrawal rejected: Savings account must keep a minimum balance of "
                    + MIN_BALANCE + " (requested " + amount + ")");
            return false;
        }
        balance -= amount;
        System.out.println("Withdrew " + amount);
        return true;
    }

    @Override
    double calculateInterest() {
        return balance * INTEREST_RATE;
    }
}

class CurrentAccount extends Account {
    private static final double OVERDRAFT_LIMIT = 5000;

    CurrentAccount(int accountNumber, double balance) {
        super(accountNumber, balance);
    }

    @Override
    boolean withdraw(double amount) {
        if (amount <= 0 || balance - amount < -OVERDRAFT_LIMIT) {
            System.out.println("Withdrawal rejected: overdraft limit of " + OVERDRAFT_LIMIT
                    + " exceeded (requested " + amount + ")");
            return false;
        }
        balance -= amount;
        System.out.println("Withdrew " + amount);
        return true;
    }
    // calculateInterest() is not overridden: current accounts earn no interest (inherits 0)
}
