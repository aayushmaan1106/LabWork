// Set 3 - Problem 10: E-Commerce Order Processing - Integrated OOP Challenge
import java.util.ArrayList;

public class c10 {
    public static void main(String[] args) {
        ArrayList<Payment> payments = new ArrayList<>();
        payments.add(new CreditCardPayment("TXN1001", "Aamir", "4242"));
        payments.add(new UPIPayment("TXN1002", "Sara", "sara@upi"));
        payments.add(new NetBankingPayment("TXN1003", "Rahul", "State Bank"));

        double[] amounts = {2500, 1200, 8000};

        System.out.println("=== Payments (amount only) ===");
        for (int i = 0; i < payments.size(); i++) {
            Payment p = payments.get(i);              // always accessed as Payment
            p.processPayment(amounts[i]);             // overridden method of the real object runs
        }

        System.out.println("\n=== Payment with transaction reference ===");
        payments.get(1).processPayment(500, "ORDER-7788");

        System.out.println("\n=== Invalid amount ===");
        payments.get(0).processPayment(-300);
        payments.get(2).processPayment(0, "ORDER-0000");
    }
}

class Payment {
    protected final String transactionId;
    protected final String payerName;

    Payment(String transactionId, String payerName) {
        this.transactionId = transactionId;
        this.payerName = payerName;
    }

    protected boolean isValid(double amount) {
        if (amount <= 0) {
            System.out.println("[" + transactionId + "] Payment FAILED: invalid amount " + amount);
            return false;
        }
        return true;
    }

    protected String methodName() { return "Generic"; }

    void processPayment(double amount) {
        if (!isValid(amount)) return;
        printSummary(amount, 0);
    }

    // Overloaded: calls the overridable processPayment(amount), so subclass logic is still used
    void processPayment(double amount, String reference) {
        System.out.println("[" + transactionId + "] Reference: " + reference);
        processPayment(amount);
    }

    protected void printSummary(double amount, double fee) {
        System.out.println("[" + transactionId + "] " + methodName() + " | Payer: " + payerName
                + String.format(" | Amount: %.2f | Fee: %.2f | Total: %.2f | Status: SUCCESS",
                        amount, fee, amount + fee));
    }
}

class CreditCardPayment extends Payment {
    private final String cardLast4;

    CreditCardPayment(String transactionId, String payerName, String cardLast4) {
        super(transactionId, payerName);
        this.cardLast4 = cardLast4;
    }

    @Override protected String methodName() { return "Credit Card (****" + cardLast4 + ")"; }

    @Override
    void processPayment(double amount) {
        if (!isValid(amount)) return;
        System.out.println("[" + transactionId + "] Verifying card and OTP...");
        printSummary(amount, amount * 0.02);              // 2% card fee
    }
}

class UPIPayment extends Payment {
    private final String upiId;

    UPIPayment(String transactionId, String payerName, String upiId) {
        super(transactionId, payerName);
        this.upiId = upiId;
    }

    @Override protected String methodName() { return "UPI (" + upiId + ")"; }

    @Override
    void processPayment(double amount) {
        if (!isValid(amount)) return;
        System.out.println("[" + transactionId + "] Sending UPI collect request...");
        printSummary(amount, 0);                          // no fee
    }
}

class NetBankingPayment extends Payment {
    private final String bankName;

    NetBankingPayment(String transactionId, String payerName, String bankName) {
        super(transactionId, payerName);
        this.bankName = bankName;
    }

    @Override protected String methodName() { return "Net Banking (" + bankName + ")"; }

    @Override
    void processPayment(double amount) {
        if (!isValid(amount)) return;
        System.out.println("[" + transactionId + "] Redirecting to " + bankName + " login...");
        printSummary(amount, 10);                         // flat Rs.10 fee
    }
}

/*
 * Challenge: correct overridden method through a Payment reference.
 * Java uses dynamic dispatch: the method that runs depends on the real object, not the reference
 * type. Even the overloaded processPayment(amount, reference) in Payment ends by calling
 * processPayment(amount), which is resolved at runtime to the subclass version.
 */
