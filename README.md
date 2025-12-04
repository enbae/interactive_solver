# interactive_solver

This program solves Wordle puzzles by intelligently guessing 5-letter words and learning from the feedback it receives. It can either solve puzzles automatically or work alongside you as you play Wordle on the official site.

## What It Does

The solver starts with thousands of possible 5-letter words and narrows them down guess by guess. After each guess, it receives feedback about which letters are correct and in the right position (green), which letters are correct but in the wrong position (yellow), and which letters don't appear in the word (gray). Using this information, it eliminates impossible words and selects its next guess strategically.

The goal is to find the secret word in as few guesses as possible by always choosing words that provide the most information about which letters might be in the solution.

## How to Use It

### Web Version

Open `index.html` in your web browser. You'll see two options:

**Automated Mode**: Enter any 5-letter word you want solved, and watch as the solver figures it out step by step. Each guess appears with colored feedback showing which letters are green (correct position), yellow (wrong position), or gray (not in word).

### In Automated Mode

When you give the solver a secret word like "apple":

1. It starts with over 500 possible words
2. Makes its first guess (usually something with common letters like "slate")
3. Compares the guess to the secret word and gets feedback
4. Eliminates words that don't match the feedback
5. Repeats until it finds the word

**Interactive Mode**: Play along with your own Wordle game. The solver suggests a word, you enter it on the official Wordle site, then tell the solver what colors you got back. It uses that information to suggest the next best guess.

When you play along with real Wordle:

1. Solver suggests a word like "slate"
2. You enter "slate" on Wordle and get colored feedback
3. You tell the solver what colors you got (g=yellow, y=green, x=gray)
4. Solver eliminates impossible words and suggests the next best guess
5. Repeat until you win

<img width="518" height="531" alt="solver" src="https://github.com/user-attachments/assets/e66955b0-752a-43d4-924e-ec5c6992b0a4" />




