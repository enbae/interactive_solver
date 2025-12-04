#include "search_util.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function should loop over the vocabulary (which contains num_words
// entries) and return the number of words in which that particular letter
// occurs.
int score_letter(char letter, char **vocabulary, size_t num_words) {
	int word_c = 0;
	for (size_t idx = 0; idx < num_words; idx++) {
		if (vocabulary[idx] != NULL) {
			if (strchr(vocabulary[idx], letter) != NULL) {
				word_c++;
			}
		}
	}
	return word_c;
}

int score_word(char *word, int *letter_scores) {
	bool letter_check[26] = {false};
	int score = 0;
	for (size_t idx = 0; idx < strlen(word); idx++) {
		char c_let = word[idx];
		int letter_idx = c_let - 'a';
		if (letter_check[letter_idx] == false) {
			int letter_score = letter_scores[letter_idx];
			score += letter_score;
			letter_check[letter_idx] = true;
		}
	}
	return score;
}

// Returns the optimum guess
char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if (score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter does not occur in the secret word.
size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words) {
	size_t r_count = 0;
	for (size_t idx = 0; idx < num_words; idx++) {
		if (vocabulary[idx] != NULL) {
			if (strchr(vocabulary[idx], letter) != NULL) {
				free(vocabulary[idx]);
				vocabulary[idx] = NULL;
				r_count++;
			}
		}
	}
	return r_count;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words) {
	size_t r_count = 0;
	for (size_t idx = 0; idx < num_words; idx++) {
		if (vocabulary[idx] != NULL) {
			bool found_l = strchr(vocabulary[idx], letter) != NULL;
			bool letter_p = vocabulary[idx][position] == letter;
			if (!found_l) {
				free(vocabulary[idx]);
				vocabulary[idx] = NULL;
				r_count++;
			}
			else if (letter_p) {
				free(vocabulary[idx]);
				vocabulary[idx] = NULL;
				r_count++;
			}
		}
	}
	return r_count;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter definitely occurs as the specified position.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words) {
	size_t r_count = 0;
	for (size_t idx = 0; idx < num_words; idx++) {
		if (vocabulary[idx] != NULL) {
			char *c_word = vocabulary[idx];
			char word_l = c_word[position];
			bool letter_p = (word_l == letter);
			if (!letter_p) {
				free(vocabulary[idx]);
				vocabulary[idx] = NULL;
				r_count++;
			}
		}
	}
	return r_count;
}

void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
