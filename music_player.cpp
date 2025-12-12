#include "music_player.h" 
#include <iostream>
#include <string>
#include <limits> 
#include <iomanip> 

using namespace std;

// ==========================================
// IMPLEMENTASI HISTORY STACK (RIWAYAT LAGU)
// ==========================================

HistoryStack::HistoryStack() {
    top = nullptr;
}

bool HistoryStack::isEmpty() {
    return top == nullptr;
}

// Push: Menambah lagu ke tumpukan paling atas
void HistoryStack::push(Song s) {
    StackNode* newNode = new StackNode;
    newNode->data = s;
    newNode->next = top;
    top = newNode;
}

// Display: Menampilkan dari yang paling baru diputar
void HistoryStack::displayHistory() {
    if (isEmpty()) {
        cout << "(Belum ada riwayat pemutaran)\n";
        return;
    }
    
    StackNode* current = top;
    cout << "\n--- RIWAYAT PEMUTARAN TERAKHIR (Stack LIFO) ---\n";
    int count = 1;
    while (current != nullptr && count <= 10) { 
        cout << count << ". " << current->data.title << " - " << current->data.artist << "\n";
        current = current->next;
        count++;
    }
    cout << "-----------------------------------------------\n";
}

// ==========================================
// IMPLEMENTASI SONG QUEUE (ANTRIAN LAGU) 
// ==========================================

SongQueue::SongQueue() {
    front = nullptr;
    rear = nullptr;
}

bool SongQueue::isEmpty() {
    return front == nullptr;
}

// Enqueue: Masuk antrian (Tambah di belakang)
void SongQueue::enqueue(Song s) {
    QueueNode* newNode = new QueueNode;
    newNode->data = s;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "[SUKSES] Lagu '" << s.title << "' masuk ke antrian.\n";
}

// Dequeue: Keluar antrian (Ambil dari depan)
Song SongQueue::dequeue() {
    if (isEmpty()) {
        Song dummy; 
        dummy.id = -1; 
        return dummy;
    }

    QueueNode* temp = front;
    Song data = temp->data;

    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return data;
}


Song SongQueue::peek() {
    if (isEmpty()) {
        Song dummy; dummy.id = -1;
        return dummy;
    }
    return front->data;
}

// Display Queue: Tampilkan daftar antrian
void SongQueue::displayQueue() {
    if (isEmpty()) {
        cout << "(Antrian Kosong)\n";
        return;
    }

    QueueNode* current = front;
    cout << "\n--- DAFTAR ANTRIAN (Queue FIFO) ---\n";
    int count = 1;
    while (current != nullptr) {
        cout << count << ". " << current->data.title << " - " << current->data.artist << "\n";
        current = current->next;
        count++;
    }
    cout << "-----------------------------------\n";
}

// ==========================================
// IMPLEMENTASI SONGLIST (DOUBLY LINKED LIST)
// ==========================================

SongList::SongList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SongList::isEmpty() {
    return head == nullptr;
}

Node* SongList::findSongById(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == id) return current;
        current = current->next;
    }
    return nullptr;
}

void SongList::addSong(Song newSong) {
    if (findSongById(newSong.id) != nullptr) {
        cout << "[ERROR] Lagu dengan ID " << newSong.id << " sudah ada!\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = newSong;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (isEmpty()) head = newNode;
    else {
        tail->next = newNode;
    }
    tail = newNode;
    size++;
}

void SongList::deleteSong(int id) {
    Node* target = findSongById(id);
    if (target == nullptr) {
        cout << "[INFO] Lagu ID " << id << " tidak ditemukan.\n";
        return;
    }
    if (target == head && target == tail) { 
        head = nullptr; tail = nullptr;
    } else if (target == head) { 
        head = head->next; head->prev = nullptr;
    } else if (target == tail) { 
        tail = tail->prev; tail->next = nullptr;
    } else { 
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    delete target;
    size--;
    cout << "[SUKSES] Lagu dihapus.\n";
}

void SongList::displayAll() {
    if (isEmpty()) {
        cout << "(Library Kosong)\n";
        return;
    }
    Node* current = head;
    cout << "--------------------------------------------------------------------------------------\n";
    cout << left << setw(5) << "ID" << "| " << setw(25) << "Judul Lagu" << "| " << setw(20) << "Artis" << "| " << setw(15) << "Genre" << "| " << setw(6) << "Tahun" << endl;
    cout << "--------------------------------------------------------------------------------------\n";
    while (current != nullptr) {
        cout << left << setw(5) << current->data.id 
             << "| " << setw(25) << current->data.title.substr(0, 24)
             << "| " << setw(20) << current->data.artist.substr(0, 19)
             << "| " << setw(15) << current->data.genre.substr(0, 14)
             << "| " << setw(6) << current->data.year << endl;
        current = current->next;
    }
    cout << "--------------------------------------------------------------------------------------\n";
}

Node* SongList::getHead() { return head; }

void SongList::updateSong(int id) {
    Node* target = findSongById(id);
    if (target == nullptr) { cout << "Lagu tidak ditemukan.\n"; return; }
    
    cout << "--- UPDATE DATA (Enter utk skip) ---\n";
    string input;
    cout << "Judul (" << target->data.title << "): "; getline(cin, input);
    if (!input.empty()) target->data.title = input;
    
    cout << "Artis (" << target->data.artist << "): "; getline(cin, input);
    if (!input.empty()) target->data.artist = input;
    
    cout << "Genre (" << target->data.genre << "): "; getline(cin, input);
    if (!input.empty()) target->data.genre = input;
    
    cout << "Album (" << target->data.album << "): "; getline(cin, input);
    if (!input.empty()) target->data.album = input;

    cout << "Tahun (" << target->data.year << "): "; 
    string y; getline(cin, y);
    if (!y.empty()) {
         try { target->data.year = stoi(y); } catch(...) {}
    }
    
    cout << "[SUKSES] Update berhasil.\n";
}

void SongList::searchSong(string keyword) {
    Node* current = head;
    bool found = false;
    cout << "\n--- HASIL PENCARIAN '" << keyword << "' ---\n";
    
    while (current != nullptr) {
        if (current->data.title.find(keyword) != string::npos || 
            current->data.artist.find(keyword) != string::npos) {
            
            if (!found) { 
                cout << "------------------------------------------------------------------\n";
                cout << left << setw(25) << "Judul" << "| " << setw(20) << "Artis" << " | ID" << endl;
                cout << "------------------------------------------------------------------\n";
            }

            cout << left 
                 << setw(25) << current->data.title.substr(0, 24)
                 << "| " << setw(20) << current->data.artist.substr(0, 19)
                 << " | " << current->data.id << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) cout << "Tidak ditemukan.\n";
    else cout << "------------------------------------------------------------------\n";
}

Node* SongList::findSimilar(Node* currentSong) {
    if (!currentSong) return nullptr;
    Node* temp = head; 
    
    // Prioritas 1: Genre
    while (temp != nullptr) {
        if (temp != currentSong && temp->data.genre == currentSong->data.genre) return temp;
        temp = temp->next;
    }
    
    // Prioritas 2: Artis
    temp = head;
    while (temp != nullptr) {
        if (temp != currentSong && temp->data.artist == currentSong->data.artist) return temp;
        temp = temp->next;
    }
    return nullptr;
}

// --- SORTING (BUBBLE SORT) ---
void SongList::sortTitleAscending() {
    if (isEmpty()) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data.title > ptr1->next->data.title) {
                Song temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    cout << "[SUKSES] Lagu diurutkan berdasarkan Judul (A-Z).\n";
}

void SongList::sortYearAscending() {
    if (isEmpty()) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data.year > ptr1->next->data.year) {
                Song temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    cout << "[SUKSES] Lagu diurutkan berdasarkan Tahun (Lama -> Baru).\n";
}