#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main () {
	
	char *words[] = { 
	    "apple", "grape", "plant", "world", "light", "night", "drink", "sweet", "bread",
		"smile", "table", "chair", "brick", "smart", "dance", "fight", "heart", "cloud",
		"earth", "field", "stone", "party", "clock", "music", "fruit", "glass", "snake",
		"river", "lucky", "dream", "horse", "candy", "knife", "plant", "plane", "sword",
		"train", "queen", "piano", "tiger", "zebra", "angel", "beach", "camel", "lemon",
		"brave", "brush", "crown", "depth", "faith", "flame", "globe", "grind", "jelly",
		"laugh", "match", "pearl", "proud", "robot", "ruler", "sauce", "scale", "shine",
		"shore", "shelf", "siren", "skate", "slice", "spice", "spine", "spoon", "stamp",
		"storm", "sugar", "sweat", "sword", "thumb", "trail", "truck", "truth", "vivid",
		"water", "whale", "wheat", "wrist", "yacht", "zesty", "blaze", "blend", "bound",
		"charm", "clear", "crisp", "dizzy", "eagle", "elite", "fancy", "fiber", "flock" 
	};
		
	int word_count = sizeof(words) / sizeof(words[0]);
	char target[10];
	char guess[10];
	int attempts = 6;
	int i;
	
	
	srand(time(NULL));
	
	strcpy(target, words[rand () %  word_count]);
	
	printf("--WELCOME TO WORD GAME--\n");
	printf("Guess the 5-letter word within 6 tries.\n");
	
	while ( attempts > 0 ) {
		
	printf("Enter your guess: ");
	scanf("%s", guess);
	
	if (strlen(guess) != 5 ) {
		printf("Please enter 5-letter word: \n");
		continue;
	}
	
	if (strcmp(target, guess) == 0) {
		printf("Congragulations! You guessed word is correctly.\n");
		break;
	}
	
	for (i=0; i<5; i++) {
		if (guess[i] == target[i]) {
			printf(" %c[T] ", guess[i]);
		}
		else if (strchr(target, guess[i])) {
			printf(" %c[F] ", guess[i]);
		}
		else {
			printf(" %c[X] ", guess[i]);
		}
	}
	printf("\n");
	
	attempts--;
	printf("Remaining attempt is: %d\n", attempts);
		
	}
	
	if ( attempts == 0) {
		printf("\nSorry, you have used all of attempts. The correct word was: %s\n", target);
		
	}
	
	return 0;
	
}
