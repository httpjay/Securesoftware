import java.util.logging.Level;
import java.util.logging.Logger;

// Remove "public" since the filename is F1013.java
class SecureLoggingExample {
    private static final Logger logger = Logger.getLogger(SecureLoggingExample.class.getName());
    
    public static void main(String[] args) {
        String userId = "user123";

        // Secure logging
        logger.log(Level.INFO, "User {0} logged in successfully", new Object[]{userId});
    }
}
