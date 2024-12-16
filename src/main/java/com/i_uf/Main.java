package com.i_uf;

import java.nio.charset.StandardCharsets;

public class Main {
    static {
        System.loadLibrary("JNI_TEST");
    }
    public static native void helloWorld();
    public static class Person {
        public final int age;
        public final String name;
        public Person(int age, String name) {
            this.age = age;
            this.name = name;
        }
        public native String getID();
    }
    public static Person first() {
        return new Person(999, "CHODCHA");
    }
    public static native Person second(Person first);
    public static Person third(Person second) {
        return new Person(second.age, second.name + "[2]");
    }
    public static native Person fourth(Person third);
    public static void main(String[] args) {
        helloWorld();
        System.out.println(fourth(third(second(first()))).getID());
    }
}
