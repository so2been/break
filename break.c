#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int score;
	char * name;
} player;

int init(void) {
	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stdout, 0, _IONBF, 0);
}

int print_menu(void) {
	printf("\n\n");
	printf("[Input Number]\n");
	printf("1. Edit name\n");
	printf("2. rock, paper, scissors\n");
	printf("3. Score Board\n");
	printf("4. Exit\n");
	printf("> ");
	return 0;
}

int score_board(player *p1, player *p2, size_t name) {
	printf("%5s %10s\n", "Score", "Name");
	if (name!= 0) {
		printf("%5d %10s\n", 0x210, "so2");
		printf("%p\n", stdout);
    // break the rule babe!
		return 0;
	}
	if (*(p2->name) == 0) {
		printf("%5x %10s\n", p1->score, p1->name);
	} else if (*(p1->name) == 0) {
		printf("%5x %10s\n", p2->score, p2->name);
	}
	else if (p1->score >= p2->score) {
		printf("%5x %10s\n", p1->score, p1->name);
		printf("%5x %10s\n", p2->score, p2->name);
	}
	return 0;
}

int rps(int random) {
	int p1;
	printf("\n");
	printf("[Input Number]\n");
	printf("1. rock\n");
	printf("2. paper\n");
	printf("3. scissors\n");
	printf("4. Random\n> ");
	scanf("%d", &p1);
	if (p1 == 1) {
		return random-1;
	} else if (p1 == 2) {
		return (random +1) % 3;
	} else if (p1 == 3) {
		return random % 3;
	} else {
		return random - 1;
	}
	printf("Win or Lose\n");
}


int main(void) {
	init();
	srand((unsigned int)time(NULL));
	
	size_t name = 0;
	size_t * ptr = &name;
	size_t size = 0x7;
	size_t name2 = 0;
	int menu, result, choice = 0;
	printf("What's your name?\n> ");
	read(0, ptr, 7);
	player p0 = {0x10, "Lee"};
	player p1 = {0, (char *)ptr};
	
	while(menu != 4) {
		ptr = &name;
		size = 0x7;
		name2 = 0;
		print_menu();
		scanf("%d", &menu);
		switch(menu) {
		case 1:
			printf("Length: ");
			read(0, &size, 0x8);
			printf("Where: ");
			read(0, &ptr, 0x8);
			printf("Name: ");
			read(0, ptr, size);
			puts("hi");
			break;
		case 2:
			int num = rand() % 3 + 1;
			result = rps(num);
			if (result == 0) {
				printf("Good Game\n");
				break;
			} else if (result == 1) {
				printf("You LOse\n");
				p0.score++;
				break;
			} else if (result == 2) {
				printf("You Win\n You have a girlfriend? [1]\n> ");
				scanf("%d", &choice);
				if (choice == 1) {
					printf("Name: ");
					read(0, &name2, size);
				}
				printf("\nWhose score would you like to change?\n");
				printf("1. p1\n");
				printf("2. p2\n> ");
				scanf("%d", &choice);
				if ((choice == 1) && (p0.score >= 0x10)) {
					printf("%s's score -10\n", p0.name);
					p0.score -= 10;
					break;
				} else if ((choice == 1) && (p0.score > p1.score)) {
					printf("%s's score -2\n", p0.name);
					p0.score-=2;
					break;
				} else if ((choice !=1) && p1.score == 0) {
					printf("Your score +4\n");
					p1.score += 4;
					break;
				} else if ((choice != 1) && p1.score < 10) {
					printf("Your score +2\n");
					printf("%s's score -2\n", p0.name);
					p1.score+=2;
					p0.score-=2;
					break;
				} else if ((choice != 1) && p1.score > 0) {
					printf("Your score +1\n");
					p1.score++;
					break;
				} 
			}
		case 3:
			p1.name = (char *)ptr;
			score_board(&p0, &p1, name2);
			break;
		case 4:
			printf("Good Byte\n");
			break;
		default:
			printf("No options for %d\n", menu);
		}
	}
	return 0;
}
