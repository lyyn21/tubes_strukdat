🎵 Console Music Player (Aplikasi Pemutar Musik)

Tugas Besar Mata Kuliah Struktur Data (CDK2AAB4) > Semester Ganjil 2025/2026

📖 Deskripsi Proyek

Console Music Player adalah simulasi aplikasi pemutar musik backend berbasis Command Line Interface (CLI). Proyek ini dikembangkan untuk mendemonstrasikan penerapan berbagai struktur data dalam pengelolaan memori yang efisien untuk fitur pemutar musik modern.

Aplikasi ini memisahkan peran akses menjadi Admin (Pengelola Data) dan User (Penikmat Musik) dengan sistem autentikasi sederhana.

🚀 Fitur & Struktur Data

Aplikasi ini mengintegrasikan 3 Struktur Data Utama sesuai spesifikasi tugas besar:

1. Doubly Linked List (Library & Playlist)

Digunakan untuk menyimpan daftar lagu utama dan playlist pengguna.

Alasan: Memungkinkan navigasi lagu dua arah (Next dan Previous) secara efisien serta penghapusan data di tengah list tanpa menggeser memori.

2. Stack / Tumpukan (History)

Digunakan untuk fitur Riwayat Pemutaran.

Prinsip LIFO (Last In First Out): Lagu yang baru saja selesai diputar akan muncul di urutan paling atas riwayat.

3. Queue / Antrian (Song Queue)

Digunakan untuk fitur Antrian Prioritas (Add to Queue).

Prinsip FIFO (First In First Out): User dapat memilih lagu untuk diputar "berikutnya". Sistem akan memprioritaskan lagu di dalam Queue sebelum kembali memutar lagu dari Playlist/Library.

✨ Fitur Unggulan Lainnya

Smart Recommendation Logic: Saat lagu habis, tombol Next bekerja dengan logika cerdas:

Cek Queue: Jika ada antrian, putar antrian.

Cek Playlist: Jika tidak ada antrian, lanjut urutan playlist.

Auto-Recommend: Jika mode library, cari lagu dengan Genre yang sama. Jika tidak ada, cari Artis yang sama.

Sorting (Pengurutan): Menggunakan algoritma Bubble Sort untuk mengurutkan lagu berdasarkan Judul (A-Z) atau Tahun Rilis.

Sequential Search: Mencari lagu berdasarkan kata kunci.

Tampilan Rapi: Output tabel diformat menggunakan library <iomanip> agar kolom lurus dan mudah dibaca.

📂 Struktur Modular File

Proyek ini menerapkan Modular Programming untuk menjaga kebersihan kode:

File

Deskripsi

music_player.h

Header File: Berisi deklarasi Struct (Song, Node) dan Class (SongList, HistoryStack, SongQueue).

music_player.cpp

Implementation File: Berisi logika fungsi dan algoritma struktur data.

main.cpp

Main Program: Berisi Menu UI, Sistem Login, dan Logika Pemutar.

🛠️ Cara Instalasi & Menjalankan

Karena program ini terdiri dari beberapa file, Anda harus mengompilasinya secara bersamaan.

Prasyarat

Pastikan Anda sudah menginstal compiler C++ (MinGW/G++).

Langkah-langkah

Clone Repository:

git clone [https://github.com/username-anda/nama-repo.git](https://github.com/username-anda/nama-repo.git)
cd nama-repo


Compile Program:
Buka terminal di folder proyek, lalu jalankan perintah berikut:

g++ main.cpp music_player.cpp -o music_app


(Catatan: Jangan hanya meng-compile main.cpp saja, error linker akan terjadi)

Jalankan Aplikasi:

Windows:

music_app.exe


Linux / Mac:

./music_app


🔑 Akun Demo (Login Credentials)

Gunakan akun berikut untuk mengakses fitur aplikasi:

Role

Username

Password

Akses Fitur

Admin

admin

admin123

CRUD Lagu, Sorting Library.

User

user

user123

Play, Playlist, Queue, History, Search.

(Ketik exit pada username untuk menutup aplikasi)

👥 Anggota Kelompok

Nama Anggota

NIM

[Nama Anggota 1]

[NIM]

[Nama Anggota 2]

[NIM]

[Nama Anggota 3]

[NIM]

Catatan:
Proyek ini dibuat untuk tujuan pendidikan sebagai bagian dari evaluasi mata kuliah Struktur Data.
