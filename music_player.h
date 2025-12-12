#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <string>
#include <iostream>

using namespace std;

// ==========================================
// 1. STRUKTUR DATA UTAMA (RECORD)
// ==========================================
struct Song {
    int id;
    string title;
    string artist;
    string genre;
    string album;
    int year;
};

// ==========================================
// 2. NODE UNTUK DOUBLY LINKED LIST (LIBRARY)
// ==========================================
struct Node {
    Song data;
    Node* next;
    Node* prev;
};

// ==========================================
// 3. NODE UNTUK STACK (HISTORY)
// ==========================================
struct StackNode {
    Song data;
    StackNode* next;
};

// ==========================================
// 4. NODE UNTUK QUEUE (ANTRIAN - FITUR BARU TAHAP 3)
// ==========================================
struct QueueNode {
    Song data;
    QueueNode* next;
};

// ==========================================
// CLASS: STACK (HISTORY - LIFO)
// ==========================================
class HistoryStack {
private:
    StackNode* top;
public:
    HistoryStack();
    void push(Song s);     
    void displayHistory();  
    bool isEmpty();
};

// ==========================================
// CLASS: QUEUE (ANTRIAN - FIFO) - FITUR BARU TAHAP 3
// ==========================================
class SongQueue {
private:
    QueueNode* front;
    QueueNode* rear;
public:
    SongQueue();
    bool isEmpty();
    void enqueue(Song s); 
    Song dequeue();       
    void displayQueue();  
};

// ==========================================
// CLASS: DOUBLY LINKED LIST (LIBRARY & PLAYLIST)
// ==========================================
class SongList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    SongList(); 
    
    // Operasi Dasar
    bool isEmpty();
    Node* findSongById(int id);
    void addSong(Song newSong);
    void deleteSong(int id);
    void displayAll();
    Node* getHead();
    void updateSong(int id);
    
    // Fitur User
    void searchSong(string keyword);
    
    // Rekomendasi (Genre -> Artis)
    Node* findSimilar(Node* currentSong);
    
    // Sorting (Bubble Sort)
    void sortTitleAscending(); 
    void sortYearAscending();  
};

#endif