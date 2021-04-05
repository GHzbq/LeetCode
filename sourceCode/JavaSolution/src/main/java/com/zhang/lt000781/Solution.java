package com.zhang.lt000781;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int answer : answers) {
            count.put(answer, count.getOrDefault(answer, 0) + 1);
        }
        int result = 0, x = 0, y = 0;
        for (Map.Entry<Integer, Integer> p : count.entrySet()) {
            y = p.getKey();
            x = p.getValue();
            result += (x + y) / (y + 1) * (y + 1);
        }
        return result;
    }
}
