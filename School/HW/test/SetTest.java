import static org.junit.Assert.assertEquals;

import org.junit.Test;

import components.set.Set;

/**
 * JUnit test fixture for {@code Set<String>}'s constructor and kernel methods.
 *
 * @author Chance Davis
 *
 */
public abstract class SetTest {

    /**
     * Invokes the appropriate {@code Set} constructor and returns the result.
     *
     * @return the new set
     * @ensures constructorTest = {}
     */
    protected abstract Set<String> constructorTest();

    /**
     * Invokes the appropriate {@code Set} constructor and returns the result.
     *
     * @return the new set
     * @ensures constructorRef = {}
     */
    protected abstract Set<String> constructorRef();

    /**
     * Creates and returns a {@code Set<String>} of the implementation under
     * test type with the given entries.
     *
     * @param args
     *            the entries for the set
     * @return the constructed set
     * @requires [every entry in args is unique]
     * @ensures createFromArgsTest = [entries in args]
     */
    private Set<String> createFromArgsTest(String... args) {
        Set<String> set = this.constructorTest();
        for (String s : args) {
            assert !set.contains(s) : "Violation of: every entry in args is unique";
            set.add(s);
        }
        return set;
    }

    /**
     * Creates and returns a {@code Set<String>} of the reference implementation
     * type with the given entries.
     *
     * @param args
     *            the entries for the set
     * @return the constructed set
     * @requires [every entry in args is unique]
     * @ensures createFromArgsRef = [entries in args]
     */
    private Set<String> createFromArgsRef(String... args) {
        Set<String> set = this.constructorRef();
        for (String s : args) {
            assert !set.contains(s) : "Violation of: every entry in args is unique";
            set.add(s);
        }
        return set;
    }

    // TODO - add test cases for constructor, add, remove, removeAny, contains, and size

    @Test
    public final void testDefaultConstructor() {
        Set<String> s = this.constructorTest();
        Set<String> sExpected = this.constructorRef();

        assertEquals(sExpected, s);
    }

    @Test
    public final void testNonEmptyConstructor() {
        Set<String> s = this.createFromArgsTest("a", "b", "c");
        Set<String> sExpected = this.createFromArgsRef("a", "b", "c");

        assertEquals(sExpected, s);
    }

    @Test
    public final void testAddToEmpty() {
        Set<String> s = this.constructorTest();
        Set<String> sExpected = this.createFromArgsRef("a");

        s.add("a");

        assertEquals(sExpected, s);
    }

    @Test
    public final void testAddEmptyToNonEmpty() {
        Set<String> s = this.createFromArgsTest("a", "b", "c");
        Set<String> sExpected = this.createFromArgsRef("", "a", "b", "c");

        s.add("");

        assertEquals(sExpected, s);
    }

    @Test
    public final void testRemoveFromNonEmpty() {
        Set<String> s = this.createFromArgsTest("a", "b", "c");
        Set<String> sExpected = this.createFromArgsRef("b", "c");

        String x = s.remove("a");

        assertEquals(sExpected, s);
        assertEquals("a", x);
    }

    @Test
    public final void testRemoveToMakeEmpty() {
        Set<String> s = this.createFromArgsTest("a");
        Set<String> sExpected = this.createFromArgsRef();

        String x = s.remove("a");

        assertEquals(sExpected, s);
        assertEquals("a", x);
    }

    @Test
    public final void testRemoveAnyToMakeEmpty() {
        Set<String> s = this.createFromArgsTest("a");
        Set<String> sExpected = this.createFromArgsRef();

        String x = s.removeAny();

        assertEquals(sExpected, s);
        assertEquals("a", x);
    }

    @Test
    public final void testEmptySize() {
        Set<String> s = this.constructorTest();
        Set<String> sExpected = this.constructorRef();

        int x = s.size();

        assertEquals(sExpected, s);
        assertEquals(0, x);
    }

    @Test
    public final void testNonEmptySize() {
        Set<String> s = this.createFromArgsTest("a", "b", "c");
        Set<String> sExpected = this.createFromArgsRef("a", "b", "c");

        int x = s.size();

        assertEquals(sExpected, s);
        assertEquals(3, x);
    }
}
