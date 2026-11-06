#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(){

 srand(time(NULL));
  int d1, d2, d3, d4;
    int x;

    do {
        d1 = rand() % 9; 
        d2 = rand() % 9;
        d3 = rand() % 9;
        d4 = rand() % 9;
        x = (d1 * 1000) + (d2 * 100) + (d3 * 10) + d4;
    } while (d1 == d2 || d1 == d3 || d1 == d4 || 
             d2 == d3 || d2 == d4 || d3 == d4);


    int tries = 0;
    int number = 0;
    int max_attempts = 10;
    int a1, a2, a3, a4; 
    
    printf("Welcome to the mastermind!\n");

  while(tries<max_attempts){
      printf("Attempt %d: Please enter a number:\n", tries + 1);
      scanf("%d", &number);
      a1 = number / 1000;
      a2 = (number / 100) % 10;
      a3 = (number / 10) % 10;
      a4 = number % 10;
        if(number == x){
            printf("Congratz you find the number:%d and your number of tries:%d\n", number, tries + 1);
            break;
        }
        else {
            int well_placed = 0;
            if (a1 == d1) well_placed++;
            if (a2 == d2) well_placed++;
            if (a3 == d3) well_placed++;
            if (a4 == d4) well_placed++;
            switch (well_placed) {
                case 0: printf("0 well placed pieces.\n"); break;
                case 1: printf("1 well placed piece.\n"); break;
                case 2: printf("2 well placed pieces.\n"); break;
                case 3: printf("3 well placed pieces.\n"); break;
                case 4: printf("4 well placed pieces.\n"); break;
                default: break;
            }
            int total_matches = 0;
            if (d1 == a1 || d1 == a2 || d1 == a3 || d1 == a4) total_matches++;
            if (d2 == a1 || d2 == a2 || d2 == a3 || d2 == a4) total_matches++;
            if (d3 == a1 || d3 == a2 || d3 == a3 || d3 == a4) total_matches++;
            if (d4 == a1 || d4 == a2 || d4 == a3 || d4 == a4) total_matches++;
            
            int misplaced = total_matches - well_placed;
            printf("%d misplaced pieces.\n\n", misplaced);
        }
        tries++;

    }

if (tries == max_attempts && number != x) {
        printf("Game over! You ran out of attempts. The code was %d.\n", x);
    }
return 0;

}