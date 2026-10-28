// Set 3 - Problem 9: Exception Handling in an Overridden Method
import java.io.FileNotFoundException;
import java.io.IOException;

public class c9 {
    public static void main(String[] args) {
        // 1) TextProcessor override throws the narrower FileNotFoundException
        TextProcessor text = new TextProcessor();
        try {
            text.process();
        } catch (FileNotFoundException e) {
            System.out.println("Caught (specific): " + e.getMessage());
        }

        // 2) Through a FileProcessor reference the caller must handle IOException
        FileProcessor fp = new TextProcessor();
        try {
            fp.process();
        } catch (IOException e) {
            System.out.println("Caught (via parent reference): " + e.getMessage());
        }

        // 3) ImageProcessor override declares no exception: no try/catch needed on its own type
        ImageProcessor image = new ImageProcessor();
        image.process();

        // 4) Overloaded versions
        try {
            fp.process("report.txt");
            fp.process("report.txt", "FAST");
            text.process("", "SLOW");          // empty filename -> IOException
        } catch (IOException e) {
            System.out.println("Caught (overload): " + e.getMessage());
        }
    }
}

class FileProcessor {
    void process() throws IOException {
        System.out.println("FileProcessor: generic processing");
    }

    // Overloaded: filename
    void process(String filename) throws IOException {
        System.out.println("FileProcessor: processing file " + filename);
    }

    // Overloaded: filename + processing mode
    void process(String filename, String mode) throws IOException {
        if (filename.isEmpty()) throw new IOException("Filename must not be empty");
        System.out.println("FileProcessor: processing " + filename + " in " + mode + " mode");
    }
}

class TextProcessor extends FileProcessor {
    @Override
    void process() throws FileNotFoundException {      // VALID: narrower (subclass) checked exception
        System.out.println("TextProcessor: looking for input.txt ...");
        throw new FileNotFoundException("input.txt not found");
    }

    // INVALID examples (uncomment to see the compile errors):
    // void process() throws Exception { }              // broader than IOException
    // void process() throws java.sql.SQLException { }  // unrelated checked exception
}

class ImageProcessor extends FileProcessor {
    @Override
    void process() {                                    // VALID: no checked exception declared
        try {
            System.out.println("ImageProcessor: resizing image ...");
            if (true) throw new IOException("corrupt image header");   // handled right here
        } catch (IOException e) {
            System.out.println("ImageProcessor handled: " + e.getMessage());
        }
    }
}

/*
 * Challenge: why can't an overriding method declare a broader checked exception?
 * Code written against the parent type only prepares for the exceptions the parent declares:
 *     FileProcessor fp = new TextProcessor();
 *     try { fp.process(); } catch (IOException e) { ... }
 * If the subclass were allowed to throw Exception (broader), this code would suddenly be
 * handed an exception it never handled, which would break the substitution principle and the
 * compiler's guarantee that all checked exceptions are handled. An override may throw the same
 * exception, a narrower one, or none at all. (Unchecked exceptions are unrestricted.)
 */
