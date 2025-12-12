#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> 
#include "music_player.h"

using namespace std;

// --- VARIABEL GLOBAL ---
SongList library;       
SongList myPlaylist;    
HistoryStack history;   
SongQueue songQueue;   
Node* currentPlaying = nullptr; 
bool isPlayingFromPlaylist = false; 

// --- AKUN LOGIN ---
const string ADMIN_USER = "admin";
const string ADMIN_PASS = "admin123";
const string USER_USER = "user";
const string USER_PASS = "user123";

// --- HELPER ---
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void cleanBuffer() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
void pressEnter() { cout << "\nTekan Enter..."; cleanBuffer(); cin.get(); }

// --- PLAYER LOGIC ---
void playSong(Node* songNode, bool fromPlaylist) {
    if (songNode == nullptr) return;
    
    currentPlaying = songNode;
    isPlayingFromPlaylist = fromPlaylist;

    // Masukkan ke History Stack
    history.push(currentPlaying->data);
    
    cout << "\n[SEDANG MEMUTAR] " << (fromPlaylist ? "(Playlist)" : "(Library)") << "\n";
    cout << "Judul  : " << currentPlaying->data.title << "\n";
    cout << "Artis  : " << currentPlaying->data.artist << "\n";
    cout << "Album  : " << currentPlaying->data.album << "\n";
    cout << "Tahun  : " << currentPlaying->data.year << "\n";
    cout << "-----------------------------------\n";

    // Tampilkan daftar lagu di bawah detail pemutar untuk referensi user
    cout << "\n[DAFTAR LAGU]\n";
    if (fromPlaylist) {
        myPlaylist.displayAll();
    } else {
        library.displayAll();
    }
}

void stopSong() {
    if (currentPlaying) {
        cout << "\n[BERHENTI] Lagu " << currentPlaying->data.title << " dihentikan.\n";
        currentPlaying = nullptr;
    } else cout << "Tidak ada lagu.\n";
}

void playNext() {
    if (currentPlaying == nullptr) { cout << "Putar lagu dulu.\n"; return; }
    
    Node* nextSong = nullptr;

    // PRIORITAS 1: CEK QUEUE (ANTRIAN)
    if (!songQueue.isEmpty()) {
        cout << "[QUEUE] Memutar lagu dari antrian prioritas...\n";
        Song queuedSong = songQueue.dequeue();
        Node* targetNode = library.findSongById(queuedSong.id);
        if (targetNode) {
            playSong(targetNode, false); 
            return; 
        }
    }

    // PRIORITAS 2: LOGIKA PLAYLIST / LIBRARY STANDAR
    if (isPlayingFromPlaylist) {
        if (currentPlaying->next != nullptr) nextSong = currentPlaying->next;
        else { cout << "Ulang dari awal playlist...\n"; nextSong = myPlaylist.getHead(); }
    } else {
        cout << "Mencari rekomendasi (Genre -> Artis)...\n";
        nextSong = library.findSimilar(currentPlaying);
        if (!nextSong) {
            cout << "Tidak ada yg mirip. Putar lagu urutan selanjutnya.\n";
            nextSong = currentPlaying->next ? currentPlaying->next : library.getHead();
        } else cout << "Rekomendasi ditemukan!\n";
    }
    
    playSong(nextSong, isPlayingFromPlaylist);
}

void playPrev() {
     if (!currentPlaying) return;
     if (currentPlaying->prev) playSong(currentPlaying->prev, isPlayingFromPlaylist);
     else cout << "Ini lagu pertama.\n";
}

// --- MENU ADMIN ---
void adminMenu() {
    int choice;
    do {
        clearScreen();
        cout << "=== MENU ADMIN ===\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Lihat Library\n";
        cout << "3. Edit Lagu\n";
        cout << "4. Hapus Lagu\n";
        cout << "5. Urutkan Lagu (Sorting)\n";
        cout << "0. Logout\n";
        cout << "Pilihan: "; 
        if (!(cin >> choice)) { cin.clear(); cleanBuffer(); choice = -1; } else cleanBuffer();

        if (choice == 1) {
            Song s;
            cout << "ID: "; cin >> s.id; cleanBuffer();
            cout << "Judul: "; getline(cin, s.title);
            cout << "Artis: "; getline(cin, s.artist);
            cout << "Genre: "; getline(cin, s.genre);
            cout << "Album: "; getline(cin, s.album);
            cout << "Tahun: "; cin >> s.year; cleanBuffer();
            library.addSong(s); cout << "Berhasil.\n"; pressEnter();
        } else if (choice == 2) { library.displayAll(); pressEnter(); }
        else if (choice == 3) {
            library.displayAll(); int id; cout << "ID Edit: "; cin >> id; cleanBuffer();
            library.updateSong(id); pressEnter();
        } else if (choice == 4) {
            library.displayAll(); int id; cout << "ID Hapus: "; cin >> id; cleanBuffer();
            library.deleteSong(id); myPlaylist.deleteSong(id); pressEnter();
        } else if (choice == 5) {
            cout << "1. Urutkan Judul (A-Z)\n2. Urutkan Tahun\nPilih: ";
            int s; cin >> s; cleanBuffer();
            if (s == 1) library.sortTitleAscending();
            else if (s == 2) library.sortYearAscending();
            library.displayAll(); pressEnter();
        }
    } while (choice != 0);
}

// --- MENU USER ---
void userMenu() {
    int choice;
    do {
        clearScreen();
        cout << "=== MENU USER ===\n";
        
        // DAFTAR MENU
        cout << "1. Lihat Library\n";
        cout << "2. Cari Lagu\n";
        cout << "3. Kelola Playlist\n";
        cout << "4. Putar dari ID\n";
        cout << "5. Lihat Riwayat (Stack)\n"; 
        cout << "6. Kelola Antrian (Queue)\n";
        cout << "7. Urutkan Library\n";
        cout << "11. Stop | 12. Next | 13. Prev\n";
        cout << "0. Logout\n";
        
        // STATUS PLAYING PINDAH KE BAWAH SINI (FOOTER)
        if (currentPlaying) {
            cout << "\n--------------------------------------------------\n";
            cout << "[PLAYING]: " << currentPlaying->data.title << " - " << currentPlaying->data.artist << "\n";
            cout << "--------------------------------------------------\n";
        } else {
            cout << "\n(Tidak ada lagu yang sedang diputar)\n";
        }

        cout << "\nPilihan: "; 
        
        if (!(cin >> choice)) { cin.clear(); cleanBuffer(); choice = -1; } else cleanBuffer();

        if (choice == 1) { library.displayAll(); pressEnter(); }
        else if (choice == 2) {
            string k; cout << "Keyword: "; getline(cin, k);
            library.searchSong(k); pressEnter();
        } else if (choice == 3) {
            int p; cout << "1. Lihat | 2. Tambah | 3. Hapus | 4. Play Playlist\nPilih: ";
            cin >> p; cleanBuffer();
            if (p == 1) myPlaylist.displayAll();
            else if (p == 2) {
                library.displayAll(); int id; cout << "ID: "; cin >> id; cleanBuffer();
                Node* s = library.findSongById(id);
                if (s) { myPlaylist.addSong(s->data); cout << "Masuk playlist.\n"; }
            } else if (p == 3) {
                myPlaylist.displayAll(); int id; cout << "ID: "; cin >> id; cleanBuffer();
                myPlaylist.deleteSong(id);
            } else if (p == 4) {
                if (!myPlaylist.isEmpty()) playSong(myPlaylist.getHead(), true);
                else cout << "Playlist kosong.\n";
            }
            pressEnter();
        } else if (choice == 4) {
            int id; cout << "ID: "; cin >> id; cleanBuffer();
            Node* t = library.findSongById(id);
            if (t) playSong(t, false); else cout << "404 Not Found.\n";
            pressEnter();
        } else if (choice == 5) {
            history.displayHistory(); 
            pressEnter();
        } else if (choice == 6) { 
            int q;
            cout << "\n-- ANTRIAN (QUEUE) --\n";
            cout << "1. Lihat Antrian\n2. Tambah Lagu ke Antrian\nPilih: ";
            cin >> q; cleanBuffer();
            if (q == 1) {
                songQueue.displayQueue();
            } else if (q == 2) {
                library.displayAll();
                int id; cout << "Masukkan ID Lagu: "; cin >> id; cleanBuffer();
                Node* s = library.findSongById(id);
                if (s) {
                    songQueue.enqueue(s->data); 
                } else cout << "ID tidak ditemukan.\n";
            }
            pressEnter();
        } else if (choice == 7) {
            cout << "1. Urutkan Judul (A-Z)\n2. Urutkan Tahun\nPilih: ";
            int s; cin >> s; cleanBuffer();
            if (s == 1) library.sortTitleAscending();
            else if (s == 2) library.sortYearAscending();
            library.displayAll(); pressEnter();
        }
        else if (choice == 11) { stopSong(); pressEnter(); }
        else if (choice == 12) { playNext(); pressEnter(); }
        else if (choice == 13) { playPrev(); pressEnter(); }
    } while (choice != 0);
}

int main() {
    // Data Dummy
    library.addSong({1, "Hati-Hati di Jalan", "Tulus", "Pop", "Manusia", 2022});
    library.addSong({2, "Gajah", "Tulus", "Pop", "Gajah", 2014});
    library.addSong({3, "Enter Sandman", "Metallica", "Metal", "Black Album", 1991});
    library.addSong({4, "Sang Dewi", "Lyodra", "Pop", "Single", 2022});
    library.addSong({5, "Nothing Else Matters", "Metallica", "Metal", "Black Album", 1991});

    while (true) {
        clearScreen();
        cout << "=== APLIKASI PEMUTAR MUSIK ===\n";
        cout << "Login (ketik 'exit' untuk keluar)\n";
        string u, p;
        cout << "Username: "; cin >> u;
        if (u == "exit") break;
        cout << "Password: "; cin >> p; cleanBuffer();

        if (u == ADMIN_USER && p == ADMIN_PASS) { adminMenu(); }
        else if (u == USER_USER && p == USER_PASS) { userMenu(); }
        else { cout << "Gagal.\n"; pressEnter(); }
    }
    return 0;
}