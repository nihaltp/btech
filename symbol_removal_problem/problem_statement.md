# Problem Statement

You are given a string `S` consisting of a list of words. The string contains lowercase alphabets and some special symbols such as (`*`, `$`, `#`).  
Our task is to make the string **good**, which means removing all the special characters along with their nearest right-side alphabets.

To do this, perform the following two operations:

1. Identify the special symbol in the given sentence.
2. Remove the special symbol and the closest alphabets present to the **right** of that special character.

---

## Input Format

- The first and only line of the input contains the string `S`.

## Output Format

- Print the good sentence obtained after performing all the operations.

---

### Constraints

- `1<= S.length <=106`
- `S[i]` is the lowercase alphabet (`a` - `z`) and the special symbols(`*`, `$` and `#`)

---

## Sample Testcase 1

### Input 1

`thw$ g##bjhdwd vdg*gh$vvdd#bdudhc`

### Output 1

`thw hdwd vdghvdddudhc`

### Explanation 1

Given the string S.

1. Iterate through the string.
2. For every special character (`*`, `$`, `#`), remove it and the **next** alphabet character to its right.
3. Return the resulting string after performing all such deletions.

---

## Sample Testcase 2

### Input 2

`$sgsbd**hg`

### Output 2

`gsbd`

### Explanation 2

Given the string `$sgsbd**hg`

1. For each special symbol, remove it and the closest character to the **right**.
2. After removing both `*` symbols and the characters `h` and `g`, and then removing `$` and `s`, we are left with `gsbd`.

---