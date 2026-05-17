#include <iostream>
using namespace std;

// Node structure for circular linked list playlist
struct Node {
  string Song;      // Song name stored in the node
  Node* Next;       // Pointer to the next node
};

// Head pointer points to the current playing song
Node* Head = nullptr;

// Move to the next song in the playlist
void NextSong()
{
    // Check if playlist is empty
    if (Head == nullptr)
    {
        cout << "Your playlist is empty" << endl;
        return;
    }
    else
    {
        // Move head to the next node
        Head = Head->Next;
        cout << "Now listening to " << Head->Song << endl;
    }
}

// Move to the previous song in the playlist
void PreviousSong()
{
    // Check if playlist is empty
    if (Head == nullptr)
    {
        cout << "Your playlist is empty" << endl;
        return;
    }
    else
    {
        // Traverse to find the node that points to Head
        Node* temp = Head;
        while (temp->Next != Head)
        {
            temp = temp->Next;
        }
        // Update Head to the previous node
        Head = temp;
        cout << "Now listening to " << Head->Song << endl;
    }
}

// Add a new song at the end of the playlist
void AddSong (string name)
{
    // Create new node
    Node* NewNode = new Node();
    NewNode->Song = name;
    NewNode->Next = Head;

    Node* temp = Head;

    // Case 1: Playlist is empty
    if (Head == nullptr)
    {
        Head = NewNode;
        NewNode->Next = Head;  // Points to itself (circular)
        return;
    }
    // Case 2: Playlist has songs
    else
    {
        // Traverse to the last node
        while (temp->Next != Head)
        {
            temp = temp->Next;
        }
    }
    // Insert new node at the end
    temp->Next = NewNode;
}

// Delete a song by name from the playlist
bool DeleteSong(string name)
{
    // Case 1: Empty playlist
    if (Head == nullptr)
    {
        cout << "Your playlist is empty" << endl;
        return false;
    }

    Node* current = Head;
    Node* previous = nullptr;

    // Search for the song to delete
    do {
        if (current->Song == name)
            break;

        previous = current;
        current = current->Next;

    } while (current != Head);

    // Case 2: Song not found
    if (current->Song != name)
    {
        return false;
    }

    // Case 3: Only one node in the list
    if (current->Next == current)
    {
        delete current;
        Head = nullptr;
        return true;
    }

    // Case 4: Delete the head node
    if (current == Head)
    {
        // Find the last node
        Node* last = Head;
        while (last->Next != Head)
            last = last->Next;

        // Bypass the head node
        last->Next = Head->Next;
        Head = Head->Next;

        delete current;
        return true;
    }

    // Case 5: Delete middle or last node
    previous->Next = current->Next;
    delete current;

    return true;
}

// Display all songs in the playlist
void DisplaySong()
{
    // Check if playlist is empty
    if (Head == nullptr)
    {
        cout << "Your playlist is empty" << endl;
        return;
    }
    else
    {
        Node* temp = Head;
        // Use do-while to print at least once (circular list)
        do {
            cout << temp->Song << endl;
            temp = temp->Next;
        } while (temp != Head);
    }
}

// Count total number of songs in the playlist
int CountSongs()
{
    if(Head == nullptr) return 0;
    
    int count = 1;
    Node* temp = Head->Next;
    
    // Traverse until we return to Head
    while(temp != Head)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

int main()
{
    // Create 5 songs manually for initial playlist
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();
    Node* d = new Node();
    Node* e = new Node();
    
    // Link nodes together
    a->Song = "1- Tamer Hosny";
    a->Next = b;
    
    b->Song = "2- Amr Diab";
    b->Next = c;
    
    c->Song = "3- Assala";
    c->Next = d;
    
    d->Song = "4- Adele";
    d->Next = e;
    
    e->Song = "5- Shereen Abd El-Wahab";
    e->Next = a;  // Last node points back to first (circular)
    
    Head = a;  // Start playing from first song

    // Display welcome message and playlist
    cout << "Welcome back to your playlist" << endl;
    cout << "Your playlist is:" << endl;
    
    // Note: We use a do-while loop instead of a while loop because in a circular linked list
    // there is no NULL at the end of the list.
    // The loop must execute at least once to visit the Head node,
    // and it stops when we come back to the Head again.
    DisplaySong();
    cout << "Now listening to " << Head->Song << endl;
    
    // Display menu options
    cout << "Choose an option:" << endl;
    cout << "Press \"N\" or \"n\" to Next Song" << endl;
    cout << "Press \"P\" or \"p\" to Previous song" << endl;
    cout << "Press \"A\" or \"a\" to Add Song" << endl;
    cout << "Press \"D\" or \"d\" to Display Song" << endl;
    cout << "Press \"X\" or \"x\" to Delete Song" << endl;
    cout << "Press \"Q\" or \"q\" to Quit" << endl;

    // Main menu loop
    string InputUser;
    while(true)
    {
        cin >> InputUser;
    
        if (InputUser == "N" || InputUser == "n")
        {
            NextSong();           // Play next song
        }
        else if (InputUser == "P" || InputUser == "p")
        {
            PreviousSong();       // Play previous song
        }
        else if (InputUser == "A" || InputUser == "a")
        {
            string name;
            cin >> ws;
            getline(cin, name);
            AddSong(name);        // Add new song
            cout << name << " added successfully, you have " << CountSongs() << " songs" << endl;
            DisplaySong();        // Show updated playlist
        }
        else if (InputUser == "X" || InputUser == "x")
        {
            string name;
            cin >> ws;
            getline(cin, name);
            if (DeleteSong(name)) // Delete song if found
            {
                cout << name << " Deleted successfully, you have " << CountSongs() << " songs" << endl;
            }
            else
            {
                cout << "Song not found" << endl;
            }
            DisplaySong();        // Show updated playlist
        }
        else if (InputUser == "Q" || InputUser == "q")
        {
            cout << "You chose to quit the playlist" << endl;
            cout << "Thank you for listening" << endl;
            break;                // Exit the program
        }
        else if (InputUser == "D" || InputUser == "d")
        {
            DisplaySong();        // Display all songs
        }
        else
        {
            cout << "You entered a wrong choice!" << endl;
            return 1;
        }
    }
    
    // Free all dynamically allocated memory
    if(Head != nullptr)
    {
        Node* start = Head;
        Node* del = Head->Next;
        
        // Delete all nodes except the first one
        while(del != start)
        {
            Node* nextNode = del->Next;
            delete del;
            del = nextNode;
        }
        // Delete the first node
        delete start;
        Head = nullptr;  // Prevent dangling pointer
    }
    
    return 0;
}