import java.io.*;

// Singleton class vulnerable to deserialization attacks
class Singleton implements Serializable {
    private static final long serialVersionUID = 1L;
    private static final Singleton INSTANCE = new Singleton();

    private Singleton() {
        if (INSTANCE != null) {
            throw new IllegalStateException("Instance already exists!");
        }
    }

    public static Singleton getInstance() {
        return INSTANCE;
    }

    // Fix: Ensure deserialization doesn't create a new instance
    protected Object readResolve() throws ObjectStreamException {
        return INSTANCE;
    }
}

// Demonstrating safe serialization and deserialization
class SerializationExample {
    public static void main(String[] args) {
        Singleton instance1 = Singleton.getInstance();

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("singleton.ser"));
             ObjectInputStream ois = new ObjectInputStream(new FileInputStream("singleton.ser"))) {
            
            oos.writeObject(instance1); // Serialize
            Singleton instance2 = (Singleton) ois.readObject(); // Deserialize
            
            System.out.println("Are instances the same? " + (instance1 == instance2)); // Should print true
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
