🎵 Console Music Player (Aplikasi Pemutar Musik)

Tugas Besar Mata Kuliah Struktur Data (CDK2AAB4)

Semester Ganjil 2025/2026

📖 Deskripsi Proyek

Console Music Player adalah simulasi aplikasi pemutar musik backend berbasis Command Line Interface (CLI). Proyek ini dikembangkan untuk mendemonstrasikan penerapan berbagai struktur data dalam pengelolaan memori yang efisien untuk fitur pemutar musik modern.

Aplikasi ini memisahkan peran akses menjadi Admin (Pengelola Data) dan User (Penikmat Musik) dengan sistem autentikasi sederhana.

🚀 Fitur & Struktur Data

Aplikasi ini mengintegrasikan tiga struktur data utama sesuai spesifikasi tugas besar.

Doubly Linked List (Library & Playlist)
Digunakan untuk menyimpan daftar lagu utama dan playlist pengguna.
Struktur ini memungkinkan navigasi lagu dua arah (Next dan Previous) secara efisien serta penghapusan data di tengah list tanpa menggeser memori.

Stack / Tumpukan (History)
Digunakan untuk fitur riwayat pemutaran lagu.
Menerapkan prinsip LIFO (Last In First Out), di mana lagu yang terakhir diputar akan berada di posisi paling atas.

Queue / Antrian (Song Queue)
Digunakan untuk fitur antrian prioritas (Add to Queue).
Menerapkan prinsip FIFO (First In First Out), di mana lagu yang ditambahkan lebih dahulu akan diputar lebih dulu sebelum kembali ke playlist atau library.

✨ Fitur Unggulan Lainnya

Smart Recommendation Logic

Saat lagu selesai diputar, tombol Next bekerja dengan alur berikut:

Jika Queue tidak kosong, sistem akan memutar lagu dari Queue.

Jika Queue kosong, pemutaran dilanjutkan ke Playlist.

Jika dalam mode Library, sistem akan merekomendasikan lagu dengan genre yang sama, dan jika tidak tersedia maka berdasarkan artis yang sama.

Sorting (Pengurutan)
Menggunakan algoritma Bubble Sort untuk mengurutkan lagu berdasarkan judul (A–Z) atau tahun rilis.

Sequential Search
Digunakan untuk mencari lagu berdasarkan kata kunci.

Tampilan Rapi
Output tabel diformat menggunakan library <iomanip> agar kolom lurus dan mudah dibaca.

📂 Struktur Modular File

Proyek ini menerapkan modular programming untuk menjaga kerapihan dan keterbacaan kode.

music_player.h:

Header file yang berisi deklarasi struct (Song, Node) dan class (SongList, HistoryStack, SongQueue).

music_player.cpp:

Implementation file yang berisi logika fungsi serta algoritma struktur data.

main.cpp:

Program utama yang berisi menu antarmuka, sistem login, dan logika pemutar musik.

🛠️ Cara Instalasi & Menjalankan

Karena program terdiri dari beberapa file, proses kompilasi harus dilakukan secara bersamaan.

Prasyarat
Pastikan compiler C++ (MinGW atau G++) sudah terpasang.


Langkah-langkah



Clone repository

git clone https://github.com/lyyn21/tubes_strukdat.git

cd tubes_strukdat

Compile program

g++ main.cpp music_player.cpp -o music_app

Jalankan aplikasi

Windows

music_app.exe

Linux / Mac

./music_app

🔑 Akun Login Aplikasi

Admin

Username: admin

Password: admin123

Akses: CRUD lagu dan sorting library

User

Username: user

Password: user123

Akses: Play lagu, playlist, queue, history, dan pencarian

Ketik exit pada input username untuk keluar dari aplikasi.

👥 Anggota Kelompok 11

Fauzi Romadhoni - 103132400025

Aditya Dwi Aryanto - 103132400027

Khairun Fahmi - 103132400035

Catatan
Proyek ini dibuat untuk tujuan pendidikan sebagai bagian dari evaluasi mata kuliah Struktur Data.
