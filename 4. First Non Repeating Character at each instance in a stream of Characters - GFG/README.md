# 4. First Non Repeating Character at each instance in a stream of Characters
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a string <strong>str&nbsp;</strong>which denotes stream of characters. Your task is to find a new string <strong>output_str</strong>.<br>
<strong>output_str&nbsp;</strong>is formed such that we have to find first non-repeating character at each instance when a character is inserted to the stream and append it at the end of&nbsp;<strong>output_str</strong>. If no such non-repeating charater is found then append 'X' at the end of&nbsp;<strong>output_str</strong></span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>str = "dabc"
<strong>Output: </strong>"dddd"
<strong>Explanation: </strong>
"d" - first non-repeating chararcter 'd'.
"da" - first non-repeating chararcter 'd'.
"dab" - first non-repeating chararcter 'd'.
"dabc" - first non-repeating chararcter 'd'</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>str = "bbe"
<strong>Output: </strong>"bXe"
<strong>Explanation: 
</strong>"b" - first non-repeating character 'b'
"bb" - no non-repeating character so 'X'
"bbe" - first non-repeating character 'e'</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You&nbsp;don't need to read or print anything. Your task is to complete the function&nbsp;<strong>firstNonRepeating()&nbsp;</strong>which takes&nbsp;<strong>str&nbsp;</strong>as input parameter and returns&nbsp;<strong>output_str</strong>.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(|str|*26)<br>
<strong>Expected Auxilary Space :&nbsp;</strong>O(1)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ |str| ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>