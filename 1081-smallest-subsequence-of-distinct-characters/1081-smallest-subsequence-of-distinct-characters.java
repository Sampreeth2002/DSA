class Solution {
    public String smallestSubsequence(String s) {
     // hold last index of every character.
		int[] lastIndex = new int[26];
		// visited array to store every char value.
		boolean[] visited = new boolean[26];
		// hold the answer sub sequence.
		Deque<Character> ansStack = new LinkedList<>();
		// prepare last index of every character
		for (int i = 0; i < s.length(); i++) {
			lastIndex[s.charAt(i) - 'a'] = i;
		}
		// iterate each char of String
		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			// if current char already visited don't do anything
			if (visited[ch - 'a']) {
				continue;
			}
			// check if top of stack > current char. and if that top element of stack is
			// repeating later.
			while (!ansStack.isEmpty() && ansStack.peek() > ch && lastIndex[ansStack.peek() - 'a'] > i) {
				// remove top element from stack as we have smaller lexicographic string
				// combination available.
				// also make visited of top element to false as we need to read it again latter
				// for placement.
				visited[ansStack.pop() - 'a'] = false;
			}
			// set visited of current char true and add curr char to answer stack
			visited[ch - 'a'] = true;
			ansStack.push(ch);
		}

		StringBuilder sb = new StringBuilder();
		// now we need to get elements from stack and add it to the stringBuilder
		while (!ansStack.isEmpty()) {
			sb.append(ansStack.pop());
		}
		// since element are in reverse order. just reverse the elements.
		return sb.reverse().toString();
    }
}