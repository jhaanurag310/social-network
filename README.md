# Social Network Management System in C

A simple **Social Network Management System** developed in **C programming** using **structures, linked lists, pointers, arrays, and dynamic memory allocation**.

The project simulates basic social networking functionality such as user registration, login, following users, viewing followers/following, unfollowing users, and removing followers.

## 📌 Features

### 👤 User Management

* Register a new user
* Login using username and password
* Prevent duplicate usernames
* Logout from the current account

### 🤝 Social Networking

* Follow another registered user
* View your followers
* View users you are following
* Unfollow a user
* Remove a follower
* Prevent users from following themselves
* Prevent duplicate follow relationships

### 🔐 Login System

* Username and password-based authentication
* Displays an error for invalid login credentials

## 🛠️ Technologies Used

* **Language:** C
* **Concepts Used:**

  * Structures
  * Pointers
  * Linked Lists
  * Arrays
  * Functions
  * Dynamic Memory Allocation
  * String Handling
  * `malloc()`
  * `strcmp()`
  * `strcpy()`

## 📂 Project Structure

```text
Social-Network-Management-System/
│
├── social_network.c
└── README.md
```

## 🧠 Data Structure

The project uses a `struct User` to represent each user.

Each user contains:

```c
struct User {
    char username[21];
    char password[21];

    struct User *followers[MAX];
    int followerCount;

    struct User *following[MAX];
    int followingCount;

    struct User *next;
};
```

### How it works

* Each user is stored as a node in a **linked list**.
* `next` points to the next registered user.
* `followers[]` stores pointers to users who follow the current user.
* `following[]` stores pointers to users whom the current user follows.
* `followerCount` keeps track of the number of followers.
* `followingCount` keeps track of the number of users being followed.

The maximum number of followers/following users is defined by:

```c
#define MAX 100
```

## ⚙️ Main Operations

| Operation       | Description                                 |
| --------------- | ------------------------------------------- |
| Register        | Creates a new user                          |
| Login           | Authenticates an existing user              |
| Follow User     | Allows a user to follow another user        |
| View Followers  | Displays users following the current user   |
| View Following  | Displays users followed by the current user |
| Unfollow User   | Removes a user from the following list      |
| Remove Follower | Removes a user from the followers list      |
| Logout          | Logs out the current user                   |
| Exit            | Closes the program                          |

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone <your-repository-url>
```

### 2. Navigate to the Project Directory

```bash
cd Social-Network-Management-System
```

### 3. Compile the Program

Using GCC:

```bash
gcc social_network.c -o social_network
```

### 4. Run the Program

On macOS/Linux:

```bash
./social_network
```

On Windows:

```bash
social_network.exe
```

## 🖥️ Program Flow

### Before Login

The program displays:

```text
1. Register
2. Login
3. Exit
Enter choice:
```

### After Login

The user gets access to:

```text
1. Follow User
2. View Followers
3. View Following
4. Unfollow User
5. Remove Follower
6. Logout
Enter choice:
```

## 💡 Example

A user can register:

```text
Username: anurag
Password: 1234
```

Another user can register:

```text
Username: rahul
Password: 5678
```

After logging in as `anurag`, the user can follow `rahul`.

The relationship is stored in both directions:

```text
anurag
   |
   | follows
   ↓
rahul
```

Therefore:

* `anurag` appears in Rahul's **Followers** list.
* `rahul` appears in Anurag's **Following** list.

If Anurag unfollows Rahul, both lists are updated.

## 🔍 Important Functions

### `findUser()`

Searches the linked list for a user by username.

```c
struct User* findUser(struct User *head, char username[])
```

### `registerUser()`

Creates a new user dynamically using `malloc()` and adds the user to the linked list.

### `loginUser()`

Checks whether the entered username and password match a registered user.

### `followUser()`

Creates a follow relationship between two users and updates both users' follower/following lists.

### `unfollowUser()`

Removes the target user from the current user's following list and updates the target user's follower list.

### `removeFollower()`

Removes a user from the current user's followers and removes the corresponding following relationship.

### `removeFromList()`

A helper function used to remove a user pointer from an array while maintaining the remaining elements.

## 📚 Concepts Demonstrated

This project was created to practice important C programming and Data Structures concepts:

* **Structures**
* **Self-referential structures**
* **Singly Linked Lists**
* **Pointers to Structures**
* **Array of Structure Pointers**
* **Dynamic Memory Allocation**
* **Functions and Modular Programming**
* **String Manipulation**
* **Searching**
* **Insertion**
* **Deletion**
* **Relationship Management**

## ⚠️ Limitations

This is a console-based educational project, so it has some limitations:

* User data is stored only in memory.
* Data is lost when the program terminates.
* Passwords are stored as plain text.
* Each user can have a maximum of 100 followers and 100 following users.
* There is no graphical user interface.
* There is no database or persistent storage.

## 🔮 Future Improvements

Possible improvements include:

* Add file handling for permanent data storage.
* Add password encryption/hashing.
* Increase or dynamically manage follower limits.
* Add posts and comments.
* Add likes and reactions.
* Add private messaging.
* Add a search feature.
* Add profile information.
* Add a graphical user interface.
* Connect the application to a database.

## 👨‍💻 Author

**Anurag Jha**

This project was developed as a C programming/Data Structures project to understand how linked lists and pointers can be used to implement relationships between users in a simple social networking system.

## ⭐ If you found this project useful

Feel free to explore the code, experiment with the data structures, and improve the project with additional features.
