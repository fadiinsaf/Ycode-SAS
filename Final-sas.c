#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

struct team
{
    char name[50];
    char lastname[50];
    char position[50];
    int id;
    int age;
    int goals;
    int Jerseynum;

}player[100], temp;

void addplayers();
void showallp();
void editplayer();
void deleplayer();
void research();
void statistique();

int count = 0;
int nextid = 1;

char findename[20];
int findeid;
int goalnum;
int pn;
int choice;
bool founde = false;

int main()
{
    
    do
    {

        printf("-------------------\n");
        printf("1.Add Player\n");
        printf("2.Show All Players\n");
        printf("3.Edit Player\n");
        printf("4.Delete a Player\n");
        printf("5.Research a Player\n");
        printf("6.Team Statistics\n");
        printf("0.Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addplayers();
            break;

        case 2:
            showallp();
            break;

        case 3:
            editplayer();
            break;

        case 4:
            deleplayer();
            break;

        case 5:
            research();
            break;

        case 6:
            statistique();
            break;

        case 0:
            system("cls");
            printf("Bye :)\n");
            sleep(2);
            break;

        default:
            system("cls");
            printf("invalid choice please try again !!\n");
            sleep(2);
            system("cls");
            break;
        }

    } while (choice != 0);

    return 0;
}

void addplayers()
{
    int poschoice;
    do
    {
        system("cls");
        printf("1.Add one player\n");
        printf("2.Add many player\n");
        printf("3.Back to main menu\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("Enter Player First Name: \n");
            getchar();
            fgets(player[count].name, sizeof(player[count].name), stdin);
            player[count].name[strcspn(player[count].name, "\n")] = '\0';

            printf("Enter Player Last Name: \n");
            fgets(player[count].lastname, sizeof(player[count].lastname), stdin);
            player[count].lastname[strcspn(player[count].lastname, "\n")] = '\0';

            printf("Enter Player Age: \n");
            scanf("%d", &player[count].age);

        do
        {
            printf("Enter Player Position: \n");
            printf("1.AT\n");
            printf("2.CM\n");
            printf("3.DF\n");
            printf("4.GK\n");
            scanf("%d", &poschoice);

            switch(poschoice)
            {
            case 1:
            strcpy(player[count].position, "AT");
            break;

            case 2:
            strcpy(player[count].position, "CM");
            break;

            case 3:
            strcpy(player[count].position, "DF");
            break;

            case 4:
            strcpy(player[count].position, "GK");
            break;

            default:
            system("cls");
            printf("invalid choice please try again !!\n");
            sleep(2);
            system("cls");
            break;
            }

        }while(poschoice != 1 && poschoice != 2 && poschoice != 3 && poschoice != 4);
            
            printf("Enter Player Goals: \n");
            scanf("%d", &player[count].goals);

            printf("Enter Player Jersey number: \n");
            scanf("%d", &player[count].Jerseynum);

            player[count].id = nextid++;
            count++;

            system("cls");
            printf("wait a momment .... \n");
            sleep(2);
            printf("Player has been added successfuly :)\n");
            sleep(2);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            printf("How many players want to add it:\n");
            scanf("%d", &pn);

            for (int i = 0; i < pn; i++)
            {
                system("cls");
                printf("Enter Player%d First Name: \n", i + 1);
                getchar();
                fgets(player[count].name, sizeof(player[count].name), stdin);
                player[count].name[strcspn(player[count].name, "\n")] = '\0';

                printf("Enter Player%d Last Name: \n", i + 1);
                fgets(player[count].lastname, sizeof(player[count].lastname), stdin);
                player[count].lastname[strcspn(player[count].lastname, "\n")] = '\0';

                printf("Enter Player%d Age: \n", i + 1);
                scanf("%d", &player[count].age);

            do
           {
                printf("Enter Player%d Position: \n", i + 1);    
                printf("1.AT\n");
                printf("2.CM\n");
                printf("3.DF\n");
                printf("4.GK\n");
                scanf("%d", &poschoice);

                switch(poschoice)
            {
            case 1:
            strcpy(player[count].position, "AT");
            break;

            case 2:
            strcpy(player[count].position, "CM");
            break;

            case 3:
            strcpy(player[count].position, "DF");
            break;

            case 4:
            strcpy(player[count].position, "GK");
            break;

            default:
            system("cls");
            printf("invalid choice please try again !!\n");
            sleep(2);
            system("cls");
            break;
            }

            }while(poschoice != 1 && poschoice != 2 && poschoice != 3 && poschoice != 4);

                printf("Enter Player%d Goals: \n", i + 1);
                scanf("%d", &player[count].goals);

                printf("Enter Player%d Jersey number: \n", i + 1);
                scanf("%d", &player[count].Jerseynum);

                player[count].id = nextid++;
                count++;
            }

            system("cls");
            printf("wait a momment .... \n");
            sleep(2);
            printf("the players has been added successfuly :)\n");
            sleep(2);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            break;

        default:
            system("cls");
            printf("invalid choice please try again !!\n");
            sleep(2);
            system("cls");
            break;
        }
    } while (choice != 3);
}

void showallp()
{
    do
    {
        system("cls");
        printf("1.show players by alphabetical arrangement\n");
        printf("2.show players by age\n");
        printf("3.Show players by position\n");
        printf("4.Back to main menu\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");

            if (count > 0)
            {

                for (int i = 0; i < count - 1; i++)
                {
                    for (int j = i + 1; j < count; j++)
                    {
                        if (strcmp(player[i].name, player[j].name) > 0)
                        {
                            temp = player[i];
                            player[i] = player[j];
                            player[j] = temp;
                        }
                    }
                }

                for (int i = 0; i < count; i++)
                {
                    printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                }
                sleep(2);
                system("pause");
                system("cls");
            }

            else
            {
                printf("no avalabile players :(\n");
                sleep(2);
                system("pause");
                system("cls");
            }
            break;

        case 2:
            system("cls");
            
            if (count > 0)
            {

                for (int i = 0; i < count; i++)
                {
                    for (int j = i + 1; j < count; j++)
                    {
                        if (player[i].age > player[j].age)
                        {
                            temp = player[i];
                            player[i] = player[j];
                            player[j] = temp;
                        }
                    }
                }

                for (int i = 0; i < count; i++)
                {
                    printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                }
                sleep(2);
                system("pause");
                system("cls");
            }

            else
            {
                printf("no avalabile players :(\n");
                sleep(2);
                system("pause");
                system("cls");
            }
            break;

        case 3:
            system("cls");

            if (count > 0)
            {

                for (int i = 0; i < count; i++)
                {
                    for (int j = i + 1; j < count; j++)
                    {
                        if (strcmp(player[i].position, player[j].position) > 0)
                        {
                            temp = player[i];
                            player[i] = player[j];
                            player[j] = temp;
                        }
                    }
                }

                for (int i = 0; i < count; i++)
                {
                    printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                }
                sleep(2);
                system("pause");
                system("cls");
            }

            else
            {
                system("cls");
                printf("no avalabile players :(\n");
                sleep(2);
                system("pause");
                system("cls");
            }
            break;

        case 4:
            system("cls");
            break;

        default:

            system("cls");
            printf("invalid choice please try again !!\n");
            sleep(2);
            system("cls");
            break;
        }
    } while (choice != 4);
}

void editplayer()
{
    int poschoice;
    system("cls");
    printf("enter player ID: \n");
    scanf("%d", &findeid);

    for (int i = 0; i < count; i++)
    {
        if (findeid == player[i].id)
        {
            system("cls");
            printf("We Found %s, what would you like to change\n\n", player[i].name);
            printf("1.Change a Player's position\n");
            printf("2.Change a Player's age\n");
            printf("3.Change goals scored by a Player\n");
            printf("4.Back to main menu\n");

            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                system("cls");

            do
            {
                printf("Edit Player Position: \n");
                printf("1.AT\n");
                printf("2.CM\n");
                printf("3.DF\n");
                printf("4.GK\n");
                scanf("%d", &poschoice);

                switch(poschoice)
                {
                case 1:
                strcpy(player[i].position, "AT");
                break;

                case 2:
                strcpy(player[i].position, "CM");
                break;

                case 3:
                strcpy(player[i].position, "DF");
                break;

                case 4:
                strcpy(player[i].position, "GK");
                break;

                default:
                system("cls");
                printf("invalid choice please try again !!\n");
                sleep(2);
                system("cls");
                break;
                }

                }while(poschoice != 1 && poschoice != 2 && poschoice != 3 && poschoice != 4);
                system("cls");
                printf("wait a momment .... \n");
                sleep(2);
                printf("The player has been successfully modified :)\n");
                sleep(2);
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                printf("Edit Player Age: \n");
                scanf("%d", &player[i].age);
                system("cls");
                printf("wait a momment .... \n");
                sleep(2);
                printf("The player has been successfully modified :)\n");
                sleep(2);
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                printf("Edit Player Goals: \n");
                scanf("%d", &player[i].goals);
                system("cls");
                printf("wait a momment .... \n");
                sleep(2);
                printf("The player has been successfully modified :)\n");
                sleep(2);
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                break;

            default:
                system("cls");
                printf("invalid choice Back to main menu ....\n");
                sleep(2);
                system("cls");
                break;
            }
            founde = true;
            break;
        }
    }

    if (founde == false)
    {
        printf("not found :(\n");
        sleep(2);
        system("pause");
        system("cls");
    }

    founde = false;
}

void deleplayer()
{

    system("cls");
    printf("enter player ID: \n");
    scanf("%d", &findeid);

    for (int i = 0; i < count; i++)
    {
        if (findeid == player[i].id)
        {
            system("cls");
            printf("We Found %s\n\n", player[i].name);
            printf("1.confirm Delete !!!!\n");
            printf("2.Cancel & back to main menu\n");
            scanf("%d", &choice);
            founde = true;

            switch (choice)
            {
            case 1:
                for(int j = i; j < count; j++)
                {
                   player[j] = player[j+1];   
                }
                system("cls");
                printf("wait a momment .... \n");
                sleep(2);
                printf("The player has been Deleted :)\n");
                sleep(2);
                system("pause");
                system("cls");
                count --;
                break;

            case 2:
                system("cls");
                break;


            default:
                system("cls");
                printf("invalid choice please try again !!\n");
                sleep(2);
                system("cls");
                break;
            }
            break;
        }
    }

    if (founde == false)
    {
        printf("not found :(\n");
        sleep(2);
        system("pause");
        system("cls");
    }
    founde = false;
}

void research()
{
    system("cls");
    do
    {
        printf("1.search by ID\n");
        printf("2.search by name\n");
        printf("3.Back to main menu\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");

            printf("enter player ID: \n");
            scanf("%d", &findeid);

            for (int i = 0; i < count; i++)
            {
                if (findeid == player[i].id)
                {
                    printf("We Founde Player, here is more information: \n");
                    printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                    founde = true;
                    break;
                }
                
            }

            if (founde == false)
            {
                printf("not found :(\n");
            }

            founde = false;
            sleep(2);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            printf("enter player name: \n");
            scanf("%s", findename);

            for (int i = 0; i < count; i++)
            {
                if (strcmp(findename, player[i].name) == 0)
                {
                    printf("Founde this player, here is more information: \n\n");
                    printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                    founde = true;
                }
            }

            if (founde == false)
            {
                printf("not found :(\n");
            }

            founde = false;

            sleep(2);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            break;

        default:
            system("cls");
            printf("invalid choice please try again !!\n");
            sleep(2);
            system("cls");
        }
    } while (choice != 3);
}

void statistique()
{
   do
    {
        system("cls");
        printf("1.Display the total number of players in the team\n");
        printf("2.Display the average age of the players\n");
        printf("3.Display the players who have scored more than X goals\n");
        printf("4.Display the top scorer\n");
        printf("5.Display the youngest and the oldest player.\n");
        printf("6.Back to main menu\n");


        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
            system("cls");
            
            if(count > 0)
            {
                system("cls");
                printf("total players in the team is => %d\n", count);
                sleep(2);
                system("pause");
            }
            else
            {
                printf("no avalabile players :(\n");
                sleep(2);
                system("pause");
                system("cls");
            }
            break;

            case 2:
            system("cls");

            float someage = 0;
            if(count > 0)
            {
                for(int i = 0; i < count; i++)
                {
                    someage += player[i].age;
                }
                someage = someage / count;

                printf("the average age of players is => %.2f\n", someage);
                sleep(2);
                system("pause");
                system("cls");
            }
            else
            {
                printf("no avalabile players :(\n");
                sleep(2);
                system("pause");
                system("cls");
            }
            break;

            case 3:
            system("cls");

            printf("Enter Goals numbers :\n");
            scanf("%d", &goalnum);
            
            for (int i = 0; i < count; i++)
            {
                if ( player[i].goals > goalnum)
                {
                    printf("here is player scored more than %d: \n", goalnum);
                    printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                    founde = true;
                }
            }

            if (founde == false)
            {
                system("cls");
                printf("no player has more than %d goals :(\n", goalnum);
            }

            founde = false;
            sleep(2);
            system("pause");
            system("cls");
            break;

            case 4:
            system("cls");

            if (count > 0)
            {

                for (int i = 0; i < count - 1; i++)
                {
                    for (int j = i + 1; j < count; j++)
                    {
                        if (player[i].goals < player[j].goals)
                        {
                            temp = player[i];
                            player[i] = player[j];
                            player[j] = temp;
                        }
                    }
                }

                printf("the top scorer is: \n\n");
                printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n", player[0].id, player[0].name, player[0].lastname, player[0].age, player[0].position, player[0].goals, player[0].Jerseynum);
                sleep(2);
                system("pause");
                system("cls");
            }

            else
            {
                printf("no avalabile players :(\n");
                sleep(2);
                system("pause");
                system("cls");
            }
            break;

            case 5:
            system("cls");
            
            if (count > 0)
            {

                for (int i = 0; i < count; i++)
                {
                    for (int j = i + 1; j < count; j++)
                    {
                        if (player[i].age < player[j].age)
                        {
                            temp = player[i];
                            player[i] = player[j];
                            player[j] = temp;
                        }
                    }
                }
                printf("The oldest Player in the team: \n\n");
                printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n\n\n", player[0].id, player[0].name, player[0].lastname, player[0].age, player[0].position, player[0].goals, player[0].Jerseynum);
                
                if(count > 1)
                {
                printf("The youngest Player in the team: \n\n");
                printf("ID: %d || First name: %s || Last name: %s || Age: %d || Position: %s || Goals: %d || Jersey numer: %d\n\n\n", player[count-1].id, player[count-1].name, player[count-1].lastname, player[count-1].age, player[count-1].position, player[count-1].goals, player[count-1].Jerseynum);
                }
                sleep(2);
                system("pause");
                system("cls");
            }

            else
            {
                printf("no avalabile players :(\n");
                sleep(2);
                system("pause");
                system("cls");
            }  
            break;

            case 6:
            system("cls");
            break;

            default:
            system("cls");
            printf("invalid choice please try again !!\n");
            sleep(2);
            system("cls");
            break;
        }

    }while(choice != 6);
}