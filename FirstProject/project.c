#include <stdio.h>
#include <string.h>
int size = 4; // Global Declaration
// Structure Starts Here
typedef struct Book
{
    int id;
    char name[20];
    char author[20];
    double price;
    double rating;
} book; // Structure Ends here

/* Function Declarations*/

void storeBook(book *);
void displayBook(book *);
void searchBook(book *);
void updateBook(book *);
void top3Books(book *);
void deleteBook(book *);
void display(int, book *);
void hardCodedStore(book *);

// Main Starts Here...
int main()
{
    char ch;
    book bk[10];
    // storeBook(bk);
    hardCodedStore(bk);
    do // Do While Loop Starts Here ...
    {
        int choice;
        printf("\nEnter The Choice To :- \n1]Display All the Book Details.\n2]Search Any Book.\n3]Update Any Of The Book Details.\n4]Delete Any Of The Book.\n5]Display Top 3 Books.\nEnter Here : ");
        scanf("%d", &choice);
        switch (choice) // Switch Starts Here ...
        {
        case 1:
            displayBook(bk);
            break;
        case 2:
            searchBook(bk);
            break;
        case 3:
            updateBook(bk);
            break;
        case 4:
            deleteBook(bk);
            break;
        case 5:
            top3Books(bk);
            break;
        default:
            printf("\nYou Have Entered Wrong Choice...\nPlease Try Again !");
        } // Switch Ends Here...
        printf("\nDo You Want to Continue...");
        printf("Press Y/y to Continue or N/n to Terminate : ");
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'n' || ch == 'N')
        {
            printf("\nProgram is Stopped...Thank You !!\n");
        }
    } while (ch == 'y' || ch == 'Y'); // Do While Loop ends Here...
}
/*Function Defination of Storing Data of Books*/
void storeBook(book *bk)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the id of book %d : ", i + 1);
        scanf("%d", &bk[i].id);
        printf("\nEnter the Name of book %d : ", i + 1);
        scanf("%s", bk[i].name);
        printf("\nEnter the Author of book %d : ", i + 1);
        scanf("%s", bk[i].author);
        printf("\nEnter the Price of book %d : ", i + 1);
        scanf("%lf", &bk[i].price);
        printf("\nEnter the Rating of book %d : ", i + 1);
        scanf("%lf", &bk[i].rating);
        printf("\n+++++++++++++++++++++++++++++++++++++\n");
    }
}
// Funtion Defination to Store Values HardCoded
void hardCodedStore(book *bk)
{
    bk[0].id = 1;
    bk[1].id = 2;
    bk[2].id = 3;
    bk[3].id = 4;
    strcpy(bk[0].name, "Book1");
    strcpy(bk[1].name, "Book2");
    strcpy(bk[2].name, "Book3");
    strcpy(bk[3].name, "Book4");
    strcpy(bk[0].author, "Shri");
    strcpy(bk[1].author, "Aniket");
    strcpy(bk[2].author, "Amol");
    strcpy(bk[3].author, "jay");
    bk[0].price = 100;
    bk[1].price = 200;
    bk[2].price = 300;
    bk[3].price = 400;
    bk[0].rating = 2.2;
    bk[1].rating = 1.2;
    bk[2].rating = 6.2;
    bk[3].rating = 4.2;
}
/*Function Defination of Displaying Data of Books*/
void displayBook(book *bk)
{
    printf("\n| -* All The Book Details Are As Follows *- |");
    printf("\n---------------------------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("\nId of Book %d is : %d ", i + 1, bk[i].id);
        printf("\nName of Book %d is : %s ", i + 1, bk[i].name);
        printf("\nAuthor of Book %d is : %s ", i + 1, bk[i].author);
        printf("\nPrice of Book %d is : %.2lf rs ", i + 1, bk[i].price);
        printf("\nRating of Book %d is : %.1lf\n", i + 1, bk[i].rating);
        printf("<><><><><><><><><><><><><><><><><><><>\n");
    }
}
/*Function Defination of Searching the Books*/
void searchBook(book *bk)
{
    int choice;
    printf("\nEnter Your Choice To Search a Book => \n1]Search a Book By Id \n2]Search a Book By Name \n3]Search a Book By Author\nENTER HERE : ");
    scanf("%d", &choice);
    // Searching the Book by Using Id of a Book
    if (choice == 1)
    {
        printf("\nSearching The Book By Book Id...");
        int bid;
        printf("\nEnter The Id Of a Book : ");
        scanf("%d", &bid);
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (bk[i].id == bid)
            {
                printf("\nBook Found !\n");
                printf("\nThe Book Details Are As Follows...\n");
                display(i, bk);
                printf("\n|| -* THANK YOU *- ||\n");
                printf("---------------------\n");
                count++;
                break;
            }
        }
        if (count == 0)
        {
            printf("\n  ! Book Not Found !\n");
            printf("X---------------------X\n");
        }
    }
    // Searching the Book by Using Name of a Book
    else if (choice == 2)
    {
        printf("\nSearching The Book By Name  Of a Book...");
        char bname[20];
        printf("\nEnter The Name Of a Book : ");
        scanf("%s", bname);
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            int ans = strcmp(bname, bk[i].name);
            if (ans == 0)
            {
                printf("\nBook Found !\n");
                printf("\nThe Book Details Are As Follows...\n");
                display(i, bk);
                count++;
                printf("\n|| -* THANK YOU *- ||\n");
                printf("---------------------\n");
                break;
            }
        }
        if (count == 0)
        {
            printf("\n  ! Book Not Found !\n");
            printf("X---------------------X\n");
        }
    }
    // Searching the Book by Using Name of Author of a Book
    else if (choice == 3)
    {
        printf("\nSearching The Book By Name Of Author Of a Book...");
        char bAuthor[20];
        printf("\nEnter The Name Of Author a Book : ");
        scanf("%s", bAuthor);
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            int ans = strcmp(bAuthor, bk[i].author);
            if (ans == 0)
            {
                printf("\nBook Found !\n");
                printf("\nThe Book Details Are As Follows...\n");
                display(i, bk);
                count++;
                printf("\n|| -* THANK YOU *- ||\n");
                printf("---------------------\n");
                break;
            }
        }
        if (count == 0)
        {
            printf("\n  ! Book Not Found !\n");
            printf("X---------------------X\n");
        }
    }
    else
    {
        printf("\nYou Entered Wrong Choice...\nPlease Try Again !\n");
    }
}
// Function Defination to Display perticular Details of Book Given by Another Function
void display(int i, book *bk)
{

    printf("\nId of Book %d is : %d ", i + 1, bk[i].id);
    printf("\nName of Book %d is : %s ", i + 1, bk[i].name);
    printf("\nAuthor of Book %d is : %s ", i + 1, bk[i].author);
    printf("\nPrice of Book %d is : %.2lf rs ", i + 1, bk[i].price);
    printf("\nRating of Book %d is : %.1lf \n", i + 1, bk[i].rating);
}
// Function Defination of Upadating the Details of a Book
void updateBook(book *bk)
{
    int choice;
    printf("\nEnter the choice Update a Book => \n1.Update the Price \n2.Update the Rating\nEnter Here : ");
    scanf("%d", &choice);
    if (choice == 1) // Updating the price of a book
    {
        printf("\nYou Are Updating The Price of Book...");
        int bid;
        printf("\nEnter The Id Of a Book To Update The Price Of That Book : ");
        scanf("%d", &bid);
        for (int i = 0; i < size; i++)
        {
            if (bid == bk[i].id)
            {
                double bprice;
                printf("\nEnter the New Price of the Book : ");
                scanf("%lf", &bprice);
                bk[i].price = bprice;
                printf("Updated Details of Given Book are : \n");
                display(i, bk);
                printf("\n|| -* THANK YOU *- ||\n");
                printf("---------------------\n");
            }
        }
    }
    else if (choice == 2) // Updating the rating of a book
    {
        printf("\nYou Are Updating The Rating Of a Book.... ");
        int bid;
        printf("\nEnter The Id Of a Book To Update The Rating Of That Book : ");
        scanf("%d", &bid);
        for (int i = 0; i < size; i++)
        {
            if (bid == bk[i].id)
            {
                double brating;
                printf("Enter the New Rating of the Book : ");
                scanf("%lf", &brating);
                bk[i].rating = brating;
                printf("Updated Details of Given Book are : \n");
                display(i, bk);
                printf("\n|| -* THANK YOU *- ||\n");
                printf("---------------------\n");
            }
        }
    }
    else
    {
        printf("\nYou Entered Wrong Choice...\nPlease Try Again !");
    }
}
// Function Defination of Top 3 Books From Given Books
void top3Books(book *bk)
{
    int i;
    book temp[20];
    char name1[20];
    char author1[20];
    for(int i = 0 ; i<size ; i++){
        temp[i].id = bk[i].id;
        temp[i].price = bk[i].price;
        temp[i].rating = bk[i].rating;
        strcpy(temp[i].name , bk[i].name);
        strcpy(temp[i].author , bk[i].author);
    }
    for (i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (temp[j].rating < temp[j + 1].rating)
            {
                double temra = temp[j].rating;
                temp[j].rating = temp[j + 1].rating;
                temp[j + 1].rating = temra;

                double tempri = temp[i].price;
                temp[j].price = temp[j + 1].price;
                temp[j + 1].price = tempri;

                int tempid = temp[j].id;
                temp[j].id = temp[j + 1].id;
                temp[j + 1].id = tempid;

                strcpy(name1, temp[j].name);
                strcpy(temp[j].name, temp[j + 1].name);
                strcpy(temp[j + 1].name, name1);

                strcpy(author1, temp[j].author);
                strcpy(temp[j].author, temp[j + 1].author);
                strcpy(temp[j + 1].author, author1);
            }
        }
    }
    printf("\n|| - * Top Three Books are as Follows * - ||\n");
    if (size <= 3)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\n");
            printf("# book %d is => \n", i + 1);
            display(i, temp);
        }
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            printf("\n");
            printf("# book %d is => \n", i + 1);
            display(i, temp);
        }
        printf("\n|| -* THANK YOU *- ||\n");
        printf("---------------------");
    }
}
// Function Defination of Delete (To delete elements in array)
void deleteBook(book *bk)
{
    int b_id;
    int flag = 0;
    printf("Enter the Id Of a Book to Delete The Book : ");
    scanf("%d", &b_id);
    for (int i = 0; i < size; i++)
    {
        if (bk[i].id == b_id)
        {
            for (int j = i; j < size; j++)
            {
                bk[j].id = bk[j + 1].id;
                bk[j].rating = bk[j + 1].rating;
                bk[j].price = bk[j + 1].price;
                strcpy(bk[j].name, bk[j + 1].name);
                strcpy(bk[j].author, bk[j + 1].author);
            }
            size--;
            printf("\nBook with Id %d is Successfully Deleted...\n", b_id);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("\nYou Have Entered Wrong Id...Please Try Again !\n");
    }
}
