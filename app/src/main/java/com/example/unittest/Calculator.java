package com.example.unittest;

public class Calculator {
    public int evaluate(String expression) {
        // Basic implementation for demo purposes.
        String[] tokens = expression.split("\\+");
        int sum = 0;
        for (String token : tokens) {
            sum += Integer.parseInt(token);
        }
        return sum;
    }
}
