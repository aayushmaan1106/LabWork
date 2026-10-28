// Set 3 - Problem 7: Covariant Return Types in Overriding
public class c7 {
    public static void main(String[] args) {
        Animal animal = new Animal("Generic Animal");
        Dog dog = new Dog("Tommy");

        // Via Animal reference pointing to an Animal
        Animal a1 = animal.reproduce();
        System.out.println("animal.reproduce() -> " + a1);

        // Via Animal reference pointing to a Dog: Dog's version runs, result seen as Animal
        Animal animalRefToDog = dog;
        Animal a2 = animalRefToDog.reproduce();
        System.out.println("animalRefToDog.reproduce() -> " + a2 + " (runtime type: " + a2.getClass().getSimpleName() + ")");

        // Via Dog reference: no cast needed, the return type is Dog (covariant)
        Dog puppy = dog.reproduce();
        System.out.println("dog.reproduce() -> " + puppy);
        puppy.fetch();      // Dog-only method is available without casting

        // Overloaded methods (different parameter types)
        System.out.println();
        dog.eat("bones");
        dog.eat(250);
    }
}

class Animal {
    protected String name;

    Animal(String name) { this.name = name; }

    Animal reproduce() {
        return new Animal("Baby " + name);
    }

    void eat(String food) { System.out.println(name + " eats " + food); }
    void eat(int grams)   { System.out.println(name + " eats " + grams + " grams of food"); }

    @Override
    public String toString() { return name; }
}

class Dog extends Animal {
    Dog(String name) { super(name); }

    @Override
    Dog reproduce() {                 // covariant return type: Dog is a subtype of Animal
        return new Dog("Puppy of " + name);
    }

    void fetch() { System.out.println(name + " fetches the ball!"); }
}

/*
 * Challenge: why is changing only the return type NOT allowed for overloading, but allowed for overriding?
 *  - Overloads are told apart by the method name + parameter types (the signature). The return
 *    type is not part of it. For a call like eat("x") the compiler looks only at the arguments,
 *    so two methods that differ only in return type would be indistinguishable: compile error.
 *  - An override has the SAME signature as the parent method, and replaces it. Returning a more
 *    specific type (a subtype) is safe because every Dog is an Animal, so code written against
 *    Animal.reproduce() still works. This is called a covariant return type.
 */
