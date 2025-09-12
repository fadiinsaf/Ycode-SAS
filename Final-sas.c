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

} player[100], temp;

void defplayer();
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
    defplayer();
    do
    {

        printf("\033[1;32m-------------------\n");
        printf("1.Add Player\n");
        printf("2.Show All Players\n");
        printf("3.Edit Player\n");
        printf("4.Delete a Player\n");
        printf("5.Research a Player\n");
        printf("6.Team Statistics\n");
        printf("0.Exit\n");
        printf("-------------------\033[0m\n");

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
            printf("\033[1;31minvalid choice please try again !!\033[0m\n");
            sleep(2);
            system("cls");
            break;
        }

    } while (choice != 0);

    return 0;
}

void defplayer()
{

    strcpy(player[count].name, "cristiano");
    strcpy(player[count].lastname, "ronaldo");
    player[count].age = 40;
    strcpy(player[count].position, "AT");
    player[count].goals = 910;
    player[count].Jerseynum = 7;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Karim");
    strcpy(player[count].lastname, "Benzema");
    strcpy(player[count].position, "AT");
    player[count].age = 35;
    player[count].goals = 350;
    player[count].Jerseynum = 9;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Luka");
    strcpy(player[count].lastname, "Modric");
    strcpy(player[count].position, "CM");
    player[count].age = 38;
    player[count].goals = 50;
    player[count].Jerseynum = 10;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Thibaut");
    strcpy(player[count].lastname, "Courtois");
    strcpy(player[count].position, "GK");
    player[count].age = 32;
    player[count].goals = 0;
    player[count].Jerseynum = 1;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Sergio");
    strcpy(player[count].lastname, "Ramos");
    strcpy(player[count].position, "DF");
    player[count].age = 39;
    player[count].goals = 100;
    player[count].Jerseynum = 4;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Vinicius");
    strcpy(player[count].lastname, "Junior");
    strcpy(player[count].position, "AT");
    player[count].age = 24;
    player[count].goals = 80;
    player[count].Jerseynum = 7;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Toni");
    strcpy(player[count].lastname, "Kroos");
    strcpy(player[count].position, "CM");
    player[count].age = 35;
    player[count].goals = 70;
    player[count].Jerseynum = 8;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Marcelo");
    strcpy(player[count].lastname, "Vieira");
    strcpy(player[count].position, "DF");
    player[count].age = 37;
    player[count].goals = 30;
    player[count].Jerseynum = 12;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Kylian");
    strcpy(player[count].lastname, "Mbappe");
    strcpy(player[count].position, "AT");
    player[count].age = 26;
    player[count].goals = 200;
    player[count].Jerseynum = 11;
    player[count].id = nextid++;
    count++;

    strcpy(player[count].name, "Casemiro");
    strcpy(player[count].lastname, "Silva");
    strcpy(player[count].position, "CM");
    player[count].age = 33;
    player[count].goals = 40;
    player[count].Jerseynum = 14;
    player[count].id = nextid++;
    count++;
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

                switch (poschoice)
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
                    printf("\033[1;31minvalid choice please try again !!\033[0m\n");
                    sleep(2);
                    system("cls");
                    break;
                }

            } while (poschoice != 1 && poschoice != 2 && poschoice != 3 && poschoice != 4);

            printf("Enter Player Goals: \n");
            scanf("%d", &player[count].goals);

            printf("Enter Player Jersey number: \n");
            scanf("%d", &player[count].Jerseynum);

            player[count].id = nextid++;
            count++;

            system("cls");
            printf("wait a momment .... \n");
            sleep(2);
            printf("\033[1;32mPlayer has been added successfully :)\033[0m\n");
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

                    switch (poschoice)
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
                        printf("\033[1;31minvalid choice please try again !!\033[0m\n");
                        sleep(2);
                        system("cls");
                        break;
                    }

                } while (poschoice != 1 && poschoice != 2 && poschoice != 3 && poschoice != 4);

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
            printf("\033[1;32mPlayer has been added successfully :)\033[0m\n");
            sleep(2);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            break;

        default:
            system("cls");
            printf("\033[1;31minvalid choice please try again !!\033[0m\n");
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
                    printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
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
                    printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
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
                    printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
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
            printf("\033[1;31minvalid choice please try again !!\033[0m\n");
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

                    switch (poschoice)
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
                        printf("\033[1;31minvalid choice please try again !!\033[0m\n");
                        sleep(2);
                        system("cls");
                        break;
                    }

                } while (poschoice != 1 && poschoice != 2 && poschoice != 3 && poschoice != 4);
                system("cls");
                printf("wait a momment .... \n");
                sleep(2);
                printf("\033[1;32mThe player has been successfully modified :)\033[0m\n");
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
                printf("\033[1;32mThe player has been successfully modified :)\033[0m\n");
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
                printf("\033[1;32mThe player has been successfully modified :)\033[0m\n");
                sleep(2);
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                break;

            default:
                system("cls");
                printf("\033[1;31minvalid choice Back to main menu ....\033[0m\n");
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
        printf("\033[1;31mnot found :(\033[0m\n");
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
            printf("\033[1;31m1. Confirm Delete !!!!\033[0m\n");
            printf("\033[1;32m2. Cancel & back to main menu\033[0m\n");
            scanf("%d", &choice);
            founde = true;

            switch (choice)
            {
            case 1:
                for (int j = i; j < count; j++)
                {
                    player[j] = player[j + 1];
                }
                system("cls");
                printf("wait a momment .... \n");
                sleep(2);
                printf("\033[1;31mThe player has been Deleted :(\033[0m\n");
                sleep(2);
                system("pause");
                system("cls");
                --count;
                break;

            case 2:
                system("cls");
                break;

            default:
                system("cls");
                printf("\033[1;31minvalid choice please try again !!\033[0m\n");
                sleep(2);
                system("cls");
                break;
            }
            break;
        }
    }

    if (founde == false)
    {
        printf("\033[1;31mnot found :(\033[0m\n");
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
                    printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                    founde = true;
                    break;
                }
            }

            if (founde == false)
            {
                printf("\033[1;31mnot found :(\033[0m\n");
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
                    printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
                    founde = true;
                }
            }

            if (founde == false)
            {
                printf("\033[1;31mnot found :(\033[0m\n");
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
            printf("\033[1;31minvalid choice please try again !!\033[0m\n");
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

            if (count > 0)
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
            if (count > 0)
            {
                for (int i = 0; i < count; i++)
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
                if (player[i].goals > goalnum)
                {
                    printf("here is player scored more than %d: \n\n", goalnum);
                    printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n\n", player[i].id, player[i].name, player[i].lastname, player[i].age, player[i].position, player[i].goals, player[i].Jerseynum);
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
                printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n", player[0].id, player[0].name, player[0].lastname, player[0].age, player[0].position, player[0].goals, player[0].Jerseynum);
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
                printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n\n", player[0].id, player[0].name, player[0].lastname, player[0].age, player[0].position, player[0].goals, player[0].Jerseynum);

                if (count > 1)
                {
                    printf("The youngest Player in the team: \n\n");
                    printf("ID: %-3d || First name: %-15s || Last name: %-15s || Age: %-3d || Position: %-3s || Goals: %-5d || Jersey numer: %-3d\n\n", player[count - 1].id, player[count - 1].name, player[count - 1].lastname, player[count - 1].age, player[count - 1].position, player[count - 1].goals, player[count - 1].Jerseynum);
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
            printf("\033[1;31minvalid choice please try again !!\033[0m\n");
            sleep(2);
            system("cls");
            break;
        }

    } while (choice != 6);
}