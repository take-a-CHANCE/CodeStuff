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
        if (containsX) {
            q.enqueue(x);
        }
        for (int i = 0; i < temp.length(); i++) {
            q.enqueue(temp.dequeue());
        }
    }

}
