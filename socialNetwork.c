#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct User {
    char username[21];
    char password[21];

    struct User *followers[MAX];
    int followerCount;

    struct User *following[MAX];
    int followingCount;

    struct User *next;
};

struct User* findUser(struct User *head, char username[])
{
    struct User *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->username, username) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

struct User* registerUser(struct User *head)
{
    char username[21];
    char password[21];

    scanf("%20s", username);

    if (findUser(head, username) != NULL)
    {
        return NULL;
    }

    scanf("%20s", password);

    struct User *newUser = malloc(sizeof(struct User));

    if (newUser == NULL)
    {
        return NULL;
    }

    strcpy(newUser->username, username);
    strcpy(newUser->password, password);

    newUser->followerCount = 0;
    newUser->followingCount = 0;

    newUser->next = head;

    return newUser;
}

struct User* loginUser(struct User *head)
{
    char username[21];
    char password[21];

    scanf("%20s", username);
    scanf("%20s", password);

    struct User *temp = findUser(head, username);

    if (temp != NULL)
    {
        if (strcmp(temp->password, password) == 0)
        {
            return temp;
        }
    }

    return NULL;
}

void viewFollowers(struct User *currentUser)
{
    int i;

    printf("\nFollowers:\n");

    if (currentUser->followerCount == 0)
    {
        printf("No followers.\n");
        return;
    }

    for (i = 0; i < currentUser->followerCount; i++)
    {
        printf("%s\n", currentUser->followers[i]->username);
    }
}

void viewFollowing(struct User *currentUser)
{
    int i;

    printf("\nFollowing:\n");

    if (currentUser->followingCount == 0)
    {
        printf("No following users.\n");
        return;
    }

    for (i = 0; i < currentUser->followingCount; i++)
    {
        printf("%s\n", currentUser->following[i]->username);
    }
}

int followUser(struct User *currentUser, struct User *otherUser)
{
    int i;

    if (currentUser == otherUser)
    {
        return 0;
    }

    if (currentUser->followingCount >= MAX ||
        otherUser->followerCount >= MAX)
    {
        return 0;
    }


    for (i = 0; i < currentUser->followingCount; i++)
    {
        if (currentUser->following[i] == otherUser)
        {
            return 0;
        }
    }

    currentUser->following[currentUser->followingCount] = otherUser;
    currentUser->followingCount++;

    otherUser->followers[otherUser->followerCount] = currentUser;
    otherUser->followerCount++;

    return 1;
}

/* Helper function */
int removeFromList(struct User *list[], int *count, struct User *user)
{
    int i, j;

    for (i = 0; i < *count; i++)
    {
        if (list[i] == user)
        {
            for (j = i; j < *count - 1; j++)
            {
                list[j] = list[j + 1];
            }

            (*count)--;

            return 1;
        }
    }

    return 0;
}

int unfollowUser(struct User *currentUser, struct User *otherUser)
{
    if (removeFromList(currentUser->following,
                       &currentUser->followingCount,
                       otherUser))
    {
        removeFromList(otherUser->followers,
                       &otherUser->followerCount,
                       currentUser);

        return 1;
    }

    return 0;
}

int removeFollower(struct User *currentUser, struct User *otherUser)
{
    if (removeFromList(currentUser->followers,
                       &currentUser->followerCount,
                       otherUser))
    {
        if (removeFromList(otherUser->following,
                           &otherUser->followingCount,
                           currentUser))
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    struct User *head = NULL;
    struct User *currentUser = NULL;

    int choice;
    char username[21];

    while (1)
    {
        if (currentUser == NULL)
        {
            
            printf("\n1. Register\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter choice: ");
            

            scanf("%d", &choice);

            if (choice == 1)
            {
                struct User *newHead = registerUser(head);

                if (newHead == NULL)
                {
                    printf("\nRegistration failed.\n");
                }
                else
                {
                    head = newHead;

                    if (newHead->next == NULL)
                    {
                        printf("Registration successful %s.\n",
                               newHead->username);
                    }
                    else
                    {
                        printf("\nRegistration successful %s.\n",
                               newHead->username);
                    }
                }
            }
            else if (choice == 2)
            {
                currentUser = loginUser(head);

                if (currentUser == NULL)
                {
                    printf("\nInvalid username or password.\n");
                }
                else
                {
                    printf("\nLogin successful %s.\n",
                           currentUser->username);
                }
            }
            else if (choice == 3)
            {
                break;
            }
            else
            {
                printf("Invalid choice. Exiting...\n");
                exit(0);
            }
        }
        else
        {
            printf("\n1. Follow User\n");
            printf("2. View Followers\n");
            printf("3. View Following\n");
            printf("4. Unfollow User\n");
            printf("5. Remove Follower\n");
            printf("6. Logout\n");
            printf("Enter choice: ");


            scanf("%d", &choice);

            if (choice == 1)
            {
                scanf("%20s", username);

                struct User *otherUser = findUser(head, username);

                if (otherUser == NULL)
                {
                    printf("User not found.\n");
                }
                else if (followUser(currentUser, otherUser))
                {
                    printf("Successfully followed %s.\n", username);
                }
                else
                {
                    printf("Cannot follow %s.\n", username);
                }
            }
            else if (choice == 2)
            {
                viewFollowers(currentUser);
            }
            else if (choice == 3)
            {
                viewFollowing(currentUser);
            }
            else if (choice == 4)
            {
                scanf("%20s", username);

                struct User *otherUser = findUser(head, username);

                if (otherUser == NULL)
                {
                    printf("\nUser not found.\n");
                }
                else if (unfollowUser(currentUser, otherUser))
                {
                    printf("\nSuccessfully unfollowed %s.\n", username);
                }
                else
                {
                    printf("\nYou are not following this user.\n");
                }
            }
            else if (choice == 5)
            {
                scanf("%20s", username);

                struct User *otherUser = findUser(head, username);

                if (otherUser == NULL)
                {
                    printf("\nUser not found.\n");
                }
                else if (removeFollower(currentUser, otherUser))
                {
                    printf("\n%s was removed from your followers.\n",
                           username);
                }
                else
                {
                    printf("\n%s is not your follower.\n", username);
                }
            }
            else if (choice == 6)
            {
                currentUser = NULL;
                printf("Logged out.\n");
            }
            else
            {
                printf("Invalid choice. Exiting...\n");
                exit(0);
            }
        }
    }

    return 0;
}