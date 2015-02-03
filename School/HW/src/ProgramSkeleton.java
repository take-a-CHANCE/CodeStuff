import components.queue.Queue;

/**
 * Put a short phrase describing the program here.
 *
 * @author Chance Davis
 *
 */
public final class ProgramSkeleton {

    /**
     * Private constructor so this utility class cannot be instantiated.
     */
    private ProgramSkeleton() {
    }

    /**
     * Main method.
     *
     * @param args
     *            the command line arguments
     */
    public static void main(String[] args) {
        /*
         * Put your main program code here
         */
    }

    /**
     * Finds {@code x} in {@code q} and, if such exists, moves it to the front
     * of {@code q}.
     *
     * @param <T>
     *            type of {@code Queue} entries
     * @param q
     *            the {@code Queue} to be searched
     * @param x
     *            the entry to be searched for
     * @updates q
     * @ensures <pre>
     * perms(q, #q)  and
     * if <x> is substring of q
     *  then <x> is prefix of q
     * </pre>
     */
    private static <T> void moveToFront(Queue<T> q, T x) {
        boolean containsX = false;
        Queue<T> temp = q.newInstance();
        for (int i = 0; i < q.length(); i++) {
            T test = q.dequeue();
            if (test.equals(x)) {
                containsX = true;
            } else {
                temp.enqueue(test);
            }
        }
        temp.flip();
        if (containsX) {
            q.enqueue(x);
            for (int i = 0; i < temp.length(); i++) {
                q.enqueue(temp.dequeue());
            }
        } else {
            for (int i = 0; i < temp.length(); i++) {
                q.enqueue(temp.dequeue());
            }
        }
    }
    
    /**
     * Finds pair with first component {@code key} and, if such exists, moves it
     * to the front of {@code q}.
     *
     * @param <K>
     *            type of {@code Pair} key
     * @param <V>
     *            type of {@code Pair} value
     * @param q
     *            the {@code Queue} to be searched
     * @param key
     *            the key to be searched for
     * @updates q
     * @ensures <pre>
     * perms(q, #q)  and
     * if there exists value: V (<(key, value)> is substring of q)
     *  then there exists value: V (<(key, value)> is prefix of q)
     * </pre>
     */
    private static <K, V> void moveToFront(Queue<Pair<K, V>> q, K key) {
        boolean containsX = false;
        Queue<Pair<K, V>> temp = q.newInstance();
        Pair<K, V> p = new SimplePair<>();

        for (int i = 0; i < q.length() && !containsX; i++) {
            Pair<K, V> test = q.dequeue();
            if (test.key().equals(key)) {
                containsX = true;
                Pair<K, V> p = new SimplePair<>(key, test.value());
            } else {
                temp.enqueue(test);
            }
        }
        if (containsX && q.length() > 0) {
            Pair<K, V> front = q.replaceFront(p);
            temp.enqueue(front);
        } else if (containsX) {
            q.enqueue(p);
        }
        q.append(temp);
    }

}
