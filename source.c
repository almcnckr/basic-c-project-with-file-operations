
//Alimcan Çakır
//20.05.2022


#include <stdio.h>
#include <ctype.h>
#include <string.h>

FILE *file;

void addPet();
void deletePet();
void updatePet();
void listPets();

typedef struct infos
{
    char petName[20];
    char petSpecie[20];
    char name[20];
    char lastName[20];
    char contactNumber[20];
}Infos;



int main()
{
    int chooser;

    printf("Welcome...\n\n");

    do
    {
        printf("\n\t      Main Menu\n");
        printf("-----------------------------------\n");
        printf("Add Pet - 1\nUpdate Pet - 2\nGet Pet Info\\List Pets - 3\nDelete Pet - 4\nExit - 0\n");
        printf("-----------------------------------\n\n");  

        printf("Enter the process number: ");
        scanf("%d", &chooser);

        switch (chooser)
        {
            case 0:
                break;
            case 1:
                addPet();
                break;
            case 2:
                updatePet();
                break;
            case 3:
                listPets();
                break;
            case 4:
                deletePet();
                break;
            default:
                printf("\n\nWrong choice!!!!\n\n");
                break;
        }
    }while(chooser != 0);


    return 0;
}

void addPet()
{
    Infos petInfo;
    char continueInput = 'Y';

    file = fopen("records.txt", "a");
    
    while (continueInput != 'N')
    {
        if(file == NULL)
        {
            printf("\nError. File cannot opened.\n");
        }
        else
        {
            printf("\nEnter \"Pet Name, Pet Specie, Owner Name & Surname, Phone Number\" sequantialy.\n");
            scanf(" %s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
            fprintf(file, "%s %s %s %s %s\n", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
            printf("\nRecord successfully added.\n");
        }
        
        getchar();
        printf("\nDo you want to continue adding records? (Y/N): ");
        scanf("%c", &continueInput);
        continueInput = toupper(continueInput);
    }

    fclose(file);
}

void deletePet()
{
    FILE *temp;
    int process, chooser;
    char confirmation;
    Infos petInfo, deleted;
    do
    {
        process = 0;

        printf("\n\t\tMenu\n");
        printf("-----------------------------------\n");
        printf("Delete Pet - 1\nDelete All Pets - 2\nMain Menu - 0\n");
        printf("-----------------------------------\n\n");  

        printf("Enter the process number: ");
        scanf("%d", &chooser);
    
        switch(chooser)
        {
            case 0:
                break;
            case 1:
                if((file = fopen("records.txt", "r")) == NULL)
                {
                    printf("\nError. File cannot opened.\n");
                    break;
                }
                printf("-----------------------------------\n");
        
                rewind(file);

                temp = fopen("recordsTemp.txt", "a");
    
                printf("\nEnter the \"Pet Name, Pet Specie, Owner Name Surname\" information of the pet to be deleted.\n");
                scanf("%s %s %s %s", deleted.petName, deleted.petSpecie, deleted.name, deleted.lastName);
                fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);

                while(!feof(file))
                {
                    if((!(strcmp(petInfo.petName, deleted.petName))) && (!(strcmp(petInfo.petSpecie, deleted.petSpecie))) && (!(strcmp(petInfo.name, deleted.name))) && (!(strcmp(petInfo.lastName, deleted.lastName))))
                    {
                        process = 1;
                    }   
                    else
                    {
                        fprintf(temp, "%s %s %s %s %s\n", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                    }

                fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);

                }

                fclose(file);
                fclose(temp);

                if (process == 0)
                {
                    printf("\nRecord does not exit.\n\n");
                    remove("recordsTemp.txt");
                }
                else
                {
                    remove("records.txt");
                    rename("recordsTemp.txt", "records.txt");
                    printf("\nRecord deleted successfully.\n\n");
                }
                    break;
            case 2:
                if((file = fopen("records.txt", "r")) == NULL)
                {
                    printf("\nError. File cannot opened.\n");
                    break;
                }
                printf("\nWarning: This process will be delete all records.!\n");
                getchar();
                printf("Do you want a continue? (Y/N): ");
                scanf("%c", &confirmation);
                confirmation = toupper(confirmation);
                fclose(file);

                if(confirmation == 'Y')
                {
                    int basari = remove("records.txt");
                
                    if(basari == 0)
                    {
                        printf("\nAll records deleted successfully.\n");
                    }
                    else
                    {
                        printf("\nProcess failed.\n");
                    }

                }

                break;                
            default:
                printf("\n\nWrong choice.\n\n");
                break;
        }
    }while(chooser != 0);    
    
}

void updatePet()
{
    FILE *temp;
    int process = 0;
    Infos deleted;
    Infos update;
    Infos petInfo;

    if((file = fopen("records.txt", "r")) == NULL)
    {
        printf("\nError. File cannot opened.\n");
    }

    else
    {
        rewind(file);

        temp = fopen("recordsTemp.txt", "a");
        
        printf("\nEnter the \"Name, Type, Owner Name Surname\" information of the pet whose record will be updated.\n");
        scanf("%s %s %s %s", deleted.petName, deleted.petSpecie, deleted.name, deleted.lastName);
        fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);

        while(!feof(file))
        {
            if((!(strcmp(petInfo.petName, deleted.petName))) && (!(strcmp(petInfo.petSpecie, deleted.petSpecie))) && (!(strcmp(petInfo.name, deleted.name))) && (!(strcmp(petInfo.lastName, deleted.lastName))))
            {
                process = 1;
                printf("\nEnter the current \"Pet Name, Pet Tour, Owner Name Surname, Phone Number\" information.\n");
                scanf("%s %s %s %s %s", update.petName, update.petSpecie, update.name, update.lastName, update.contactNumber);
                fprintf(temp,"%s %s %s %s %s\n", update.petName, update.petSpecie, update.name, update.lastName, update.contactNumber);
            }
            else
            {
                fprintf(temp, "%s %s %s %s %s\n", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
            }

            fscanf(file, " %s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);

        }

        fclose(file);
        fclose(temp);

        if (process == 0)
        {
            printf("\nRecord does not exist.\n\n");
            remove("recordsTemp.txt");
        }
        else
        {
            remove("records.txt");
            rename("recordsTemp.txt", "records.txt");
            printf("\nRecord updated successfully.\n\n");
        }

    }

    fclose(file);
}

void listPets()
{
    Infos petInfo;
    char continueInput = 'E';
    char query1[20];
    char query2[20];
    int queryType, process;

    if((file = fopen("records.txt", "r")) == NULL)
    {
        printf("Error. File cannot opened.\n");
    }
    else
    {
        do
        {
            process = 0;

            printf("\n\n\t\tMenu\n");
            printf("-----------------------------------\n");
            printf("Pet Name - 1\nPet Specie - 2\nOwner Name - 3\nList all records - 4\nMain Menu - 0\n");
            printf("-----------------------------------\n\n");
            printf("Choose the query type: ");
            scanf("%d", &queryType);

            switch (queryType)
            {
                case 0:
                    break;
                case 1:
                    printf("\nEnter the name of the pet whose information you want to list.\n");
                    scanf("%s", query1);
                    rewind(file);
                    fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                    printf("\n\nListing records...\n---------------------------------------------------\n");

                    while(!feof(file))
                    {
                        if(!(strcmp(petInfo.petName, query1)))
                        {
                            printf("%s %s %s %s %s\n", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                            process = 1;

                        }

                        fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);

                    }

                    printf("---------------------------------------------------\n");

                    if(process == 1)
                    {
                        printf("\nRecords listed successfully.\n\n");
                    }
                    
                    else
                    {
                        printf("\nRecord does not exist.\n\n");
                    }

                    break;
                case 2:
                    printf("\nEnter the specie of pet whose information you want to list..\n");
                    scanf("%s", query1);
                    rewind(file);
                    fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                    printf("\n\nListing records...\n---------------------------------------------------\n");

                    while(!feof(file))
                    {
                        if(!(strcmp(petInfo.petSpecie, query1)))
                        {
                            printf("%s %s %s %s %s\n", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                            process = 1;
                        }

                        fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);

                    }

                    printf("---------------------------------------------------\n");

                    if(process == 1)
                    {
                        printf("\nRecords listed successfully.\n\n");
                    }
                    else
                    {
                        printf("\nRecord does not exist.\n\n");
                    }

                    break;
                case 3:
                    printf("\nEnter the name and surname of the owner of the pet whose information you want to list.\n");
                    scanf("%s %s", query1, query2);
                    rewind(file);
                    fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                    printf("\n\nListing Records...\n---------------------------------------------------\n");

                    while(!feof(file))
                    {
                        if((!(strcmp(petInfo.name, query1))) && (!(strcmp(petInfo.lastName, query2))))
                        {
                            printf("%s %s %s %s %s\n", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                            process = 1;
                        }

                        fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);

                    }

                    printf("---------------------------------------------------\n");

                    if(process == 1)
                    {
                        printf("\nRecords listed successfully.\n\n");
                    }
                    
                    else
                    {
                        printf("\nRecord does not exit.\n\n");
                    }

                    break;
                case 4:
                    rewind(file);
                    fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                    printf("\n\nListing Records...\n---------------------------------------------------\n");

                    while (!feof(file))
                    {
                        printf("%s %s %s %s %s\n", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                        fscanf(file, "%s %s %s %s %s", petInfo.petName, petInfo.petSpecie, petInfo.name, petInfo.lastName, petInfo.contactNumber);
                    }

                    printf("---------------------------------------------------\n\n");

                    break;
                default:
                    printf("\n\nWrong choice!!!!\n\n");
                    break;
            }

        }while(queryType != 0);
        
    }

    fclose(file);
}