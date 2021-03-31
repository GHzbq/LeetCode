package com.zhang.lt000061;

import java.util.ArrayList;
import java.util.Collections;

public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        ListNode pCur = head;
        while (pCur != null) {
            numbers.add(pCur.val);
            pCur = pCur.next;
        }
        Collections.rotate(numbers, k % numbers.size());
        pCur = head;
        for (Integer val : numbers) {
            pCur.val = val;
            pCur = pCur.next;
        }
        return head;
    }
}
