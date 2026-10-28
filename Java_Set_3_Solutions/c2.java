// Set 3 - Problem 2: Method Overloading with Type Promotion and Ambiguity
public class c2 {
    public static void main(String[] args) {
        Calculator calc = new Calculator();

        System.out.println("calculate(10, 20)       -> " + calc.calculate(10, 20));
        System.out.println("calculate(10.5, 20.5)   -> " + calc.calculate(10.5, 20.5));
        System.out.println("calculate(10L, 20L)     -> " + calc.calculate(10L, 20L));
        System.out.println("calculate(10, 20.5)     -> " + calc.calculate(10, 20.5));
        System.out.println("calculate(10, 20.5f)    -> " + calc.calculate(10, 20.5f));   // float promoted to double
        System.out.println("calculate(1.5f, 2.5f)   -> " + calc.calculate(1.5f, 2.5f));  // only (double,double) fits
        System.out.println("calculate(10L, 20.5)    -> " + calc.calculate(10L, 20.5));
        System.out.println("calculate((long)10, 20L)-> " + calc.calculate((long) 10, 20L)); // explicit cast removes ambiguity

        // calc.calculate(10, 20L);   // COMPILE ERROR: reference to calculate is ambiguous
    }
}

class Calculator {
    String calculate(int a, int b)       { return "(int,int) = " + (a + b); }
    String calculate(double a, double b) { return "(double,double) = " + (a + b); }
    String calculate(long a, long b)     { return "(long,long) = " + (a + b); }
    String calculate(int a, double b)    { return "(int,double) = " + (a + b); }
}

/*
 * Predictions:
 *  calculate(10, 20)    -> (int,int): exact match, always preferred.
 *  calculate(10, 20.5f) -> (int,double): float can only widen to double; (int,double) is more
 *                          specific than (double,double) because int widens to double.
 *  calculate(10, 20L)   -> AMBIGUOUS (compile error). Applicable: (long,long), (double,double),
 *                          (int,double). (long,long) beats (double,double), but (long,long) and
 *                          (int,double) are not comparable: the first is better in argument 2 for
 *                          long, the second is better in argument 1 for int. No single most
 *                          specific method exists, so the compiler reports the ambiguity.
 *
 * Fix for ambiguity: cast an argument, e.g. calculate((long) 10, 20L), or remove an overload.
 */
