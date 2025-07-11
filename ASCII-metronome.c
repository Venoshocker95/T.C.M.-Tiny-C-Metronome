#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>



void printMenu();
void getMenuChoice();
int askBpm();
void print2_4(int);
void print3_4(int);
void print4_4(int);



/*+-----------------------------------------
  | Cleans the input buffer
  +-----------------------------------------*/
void cleanInput()
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}



/*+-----------------------------------------
  | Prints the software "splash art"
  +-----------------------------------------*/
void printLogo()
{
    system("cls");

    printf("+===================================================================================================+\n");
    printf("|         /\\            .-..-._   .-._..;;;;.     .;;;;.                                            |\n");
    printf("|     _  / |    .;;;.`-' .: (_)`-'    ' .;'  `   ' .;'  `                                           |\n");
    printf("|    (  /  |  .;;  (_)   ::            .;'        .;'                                               |\n");
    printf("|     `/.__|_.'`;;;.     ::   _       .;'        .;'                                                |\n");
    printf("| .:' /    |   _   `:    `: .; )     .;'        .;'                                                 |\n");
    printf("|(__.'     `-'(_.;;;'      `--'  .;;;;;;;;;'.;;;;;;;;;'                                             |\n");
    printf("|      .-.              .-.-.;;;;;;'.-.                     .-.                  .-.              .-|\n");
    printf("|       .;|/:   .;;;.`-' (_)  .;   (_) )-.       .;;.    .-   ;  :    .;;.    .-  .;|/:   .;;;.`-'  |\n");
    printf("|      .;   :  ;;  (_)        :      .:   \\     ;;  `;`-'   .;:  :   ;;  `;`-'   .;   :  ;;  (_)    |\n");
    printf("|     .;    :  .;;; .-.     .:'     .::.   )   ;;    :.    .;' \\ :  ;;    :.    .;    :  .;;; .-.   |\n");
    printf("| .:'.;     : ;;  .;  ;   .-:._   .-:. `:-'   ;;     ;'.:'.;    \\: ;;     ;'.:'.;     : ;;  .;  ;   |\n");
    printf("|(__.'      `.`;.___.'   (_/  `- (_/     `:._.`;.__.' (__.'      `.`;.__.' (__.'      `.`;.___.'    |\n");
    printf("+===================================================================================================+\n");
    printf("\n");

    printMenu();

}



/*+-----------------------------------------
  | Prints the MAIN MENU
  +-----------------------------------------*/
void printMenu()
{
    printf("         CHOOSE TIME SIGNATURE ex:(ENTER 4 FOR 4/4)\n\n");
    printf("    [2] >> 2/4      [3] >> 3/4      [4] >> 4/4      [0] >> QUIT : ");

    getMenuChoice();

}



/*+--------------------------------------------------------
  | Gets and validates the menu's input, uses a switch-case
  | to determine which function is going to be called
  +--------------------------------------------------------*/
void getMenuChoice()
{
    int usrChoice = 0;
    int bpm = 0;

    while(1)
    {
        if(scanf(" %d", &usrChoice) != 1)
        {
            //If the input is not a valid integer
            Beep(800,500);
            printf("\n\n<< INVALID INPUT. ENTER A NUMBER...>>");
            Sleep(2000);
            cleanInput();
            system("cls");
            printMenu();
            continue;
        }
        
        switch(usrChoice)
        {
            case 0:
                Beep(1800, 500);
                printf("\n\n >> QUITTING PROGRAM...");
                Sleep(1000);
                exit(0);
            case 2:
                Beep(1800, 500);
                printf("\n\n >> SIGNATURE SELECTED: 2/4...");
                Sleep(2000);
                bpm = askBpm();
                print2_4(bpm);
                return;
            case 3:
                Beep(1800, 500);
                printf("\n\n >> SIGNATURE SELECTED: 3/4...");
                Sleep(2000);
                bpm = askBpm();
                print3_4(bpm);
                return;
            case 4:
                Beep(1800, 500);
                printf("\n\n >> SIGNATURE SELECTED 4/4...");
                Sleep(2000);
                bpm = askBpm();
                print4_4(bpm);
                return;
            default:
                Beep(800, 500);
                printf("\n\n >> UNRECOGNIZED INPUT...RETRY...");
                Sleep(2000);
                system("cls");
                printMenu();
                break;
        }
    }
}


/*+--------------------------------------------------------
  | Asks the user for the desired "amount" of BPMs, if 
  | the user enters something non numeric, the cycle will
  | loop back ask the question again.
  | Same thing if the BPMs entered are < 10 or > 1000
  +--------------------------------------------------------*/
int askBpm()
{
    unsigned int bpm = 0;

    while(1)
    {
        printf("\n\nENTER BPM: ");
        if(scanf(" %d", &bpm) != 1)
        {
            //If the input is not a valid integer
            Beep(800,500);
            printf("\n\n<< INVALID INPUT. ENTER A NUMBER...>>");
            cleanInput();
            Sleep(1000);
            system("cls");
            continue;
        }
        else if(bpm < 10 || bpm > 1000)
        {
            //If the bpm number is too high or too low
            Beep(800,500);
            printf("\n\n<< BPM TOO HIGH/LOW. BPM RANGE: 10 ~ 1000... >>");
            cleanInput();
            Sleep(1000);
            system("cls");
            continue;
        }
        else
        {
            break;
        }
    }

    return bpm;
}



/*+--------------------------------------------------------
  | Prints to screen the 2/4 time signature N times,
  | as per user's choice.
  | 2/4 is used for marches, polka etc...
  +--------------------------------------------------------*/
void print2_4(int bpm)
{
    system("cls");

    const int beatDur = (60000 / bpm);

    unsigned int numLoops = 0;
    unsigned int count = 0;

    while(1)
    {
        printf("NUMBER OF LOOPS: ");
        if(scanf(" %d", &numLoops) != 1)
        {
            //If the input is not a valid integer
            Beep(800,500);
            printf("\n\n<< INVALID INPUT. ENTER A NUMBER...>>");
            cleanInput();
            Sleep(1000);
            system("cls");
            continue;
        }
        else
        {
            printf("3... ");
            Sleep(1000);
            printf("2... ");
            Sleep(1000);
            printf("1...\n\n");
            Sleep(1000);
            while(count < numLoops)
            {
                printf("| X ");
                Beep(1000,50);
                Sleep(beatDur - 50);

                printf("* ");
                Beep(800, 50);
                Sleep(beatDur - 50);

                count++;

                if(count != 0 && count % numLoops == 0 || count % 10 == 0)
                {
                    printf("|\n");
                }
            } 
        }

        break;
    }

    printf("\n\nPRESS ENTER TO GO TO MAIN MENU\n");
    cleanInput();
    getchar();
    system("cls");
    printLogo();

}



/*+--------------------------------------------------------
  | Prints to screen the 3/4 time signature N times,
  | as per user's choice.
  | 3/4 is used for waltzer, mazurka, minuets etc...
  +--------------------------------------------------------*/
void print3_4(int bpm)
{
    system("cls");

    const int beatDur = (60000 / bpm);

    unsigned int numLoops = 0;
    unsigned int count = 0;

    while(1)
    {
        printf("NUMBER OF LOOPS: ");
        if(scanf(" %d", &numLoops) != 1)
        {
            //If the input is not a valid integer
            Beep(800,500);
            printf("\n\n<< INVALID INPUT. ENTER A NUMBER...>>");
            cleanInput();
            Sleep(1000);
            system("cls");
            continue;
        }
        else
        {
            printf("3... ");
            Sleep(1000);
            printf("2... ");
            Sleep(1000);
            printf("1...\n\n");
            Sleep(1000);
            while(count < numLoops)
            {
                printf("| X ");
                Beep(1000,50);
                Sleep(beatDur - 50);

                printf("* ");
                Beep(800, 50);
                Sleep(beatDur - 50);

                printf("* ");
                Beep(800, 50);
                Sleep(beatDur - 50);

                count++;

                if(count != 0 && count % numLoops == 0 || count % 10 == 0)
                {
                    printf("|\n");
                }
            } 
        }

        break;
    }

    printf("\n\nPRESS ENTER TO GO TO MAIN MENU\n");
    cleanInput();
    getchar();
    system("cls");
    printLogo();

}



/*+--------------------------------------------------------
  | Prints to screen the 4/4 time signature N times,
  | as per user's choice.
  | 4/4 is used for rock, pop, dance etc...
  +--------------------------------------------------------*/
void print4_4(int bpm)
{
     system("cls");

    const int beatDur = (60000 / bpm);

    unsigned int numLoops = 0;
    unsigned int count = 0;

    while(1)
    {
        printf("NUMBER OF LOOPS: ");
        if(scanf(" %d", &numLoops) != 1)
        {
            //If the input is not a valid integer
            Beep(800,500);
            printf("\n\n<< INVALID INPUT. ENTER A NUMBER...>>");
            cleanInput();
            Sleep(1000);
            system("cls");
            continue;
        }
        else
        {
            printf("3... ");
            Sleep(1000);
            printf("2... ");
            Sleep(1000);
            printf("1...\n\n");
            Sleep(1000);
            while(count < numLoops)
            {
                printf("| X ");
                Beep(1000,50);
                Sleep(beatDur - 50);

                printf("* ");
                Beep(800, 50);
                Sleep(beatDur - 50);

                printf("* ");
                Beep(800, 50);
                Sleep(beatDur - 50);

                printf("* ");
                Beep(800, 50);
                Sleep(beatDur - 50);

                count++;

                if(count != 0 && count % numLoops == 0 || count % 10 == 0)
                {
                    printf("|\n");
                }
            } 
        }

        break;
    }

    printf("\n\nPRESS ENTER TO GO TO MAIN MENU\n");
    cleanInput();
    getchar();
    system("cls");
    printLogo();
}



/* MAIN */
int main()
{
    system("color 0a");

    Beep(800, 500);
    Beep(800, 500);
    Beep(1300, 800);
    printLogo();

    return 0;
}