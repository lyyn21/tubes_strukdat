🎵 Aplikasi Konsol Pemutar Musik (Music Player Console)

Tugas Besar Mata Kuliah Struktur Data (CDK2AAB4) > Semester Ganjil 2025/2026

📖 Deskripsi Proyek

Aplikasi ini adalah simulasi pemutar musik berbasis Command Line Interface (CLI) yang dikembangkan menggunakan bahasa C++. Proyek ini bertujuan untuk mengimplementasikan struktur data Doubly Linked List dalam pengelolaan data lagu yang kompleks, termasuk manajemen memori dinamis untuk Library lagu dan Playlist pengguna.

Program ini memisahkan peran akses menjadi Admin (pengelola data) dan User (penikmat musik) dengan fitur autentikasi sederhana.

🚀 Fitur Utama

1. Struktur Data

Doubly Linked List: Digunakan untuk navigasi lagu (Next/Previous) yang efisien dan fleksibel.

Struct & Class: Penggunaan tipe data bentukan untuk merepresentasikan entitas Lagu dan Node.

2. Manajemen Akses (Login System)

Admin: Memiliki akses penuh untuk menambah, mengubah, dan menghapus lagu dari database utama (Library).

User: Memiliki akses untuk memutar musik, mencari lagu, dan mengelola playlist pribadi.

3. Fitur Unggulan

Smart Recommendation: Saat memutar lagu dari Library, fitur Next akan otomatis mencari lagu yang mirip.

Logika: Mencari lagu dengan Genre yang sama terlebih dahulu. Jika tidak ada, mencari lagu dengan Nama Artis yang sama.

Playlist Management: User dapat membuat daftar putar sendiri dengan mengambil lagu dari Library.

Sequential Search: Pencarian lagu berdasarkan kata kunci pada Judul atau Artis.

Tampilan Tabel Rapi: Menggunakan formatting iomanip agar data lagu tampil lurus dan mudah dibaca.

📂 Struktur File

Proyek ini menggunakan konsep modular programming:

music_player.h: Header file berisi definisi Struct (Song, Node) dan Deklarasi Class (SongList).

music_player.cpp: File implementasi berisi logika fungsi linked list.

main.cpp: File utama berisi menu antarmuka (UI), logika login, dan alur program utama.

🔑 Akun Demo (Credentials)

Gunakan akun berikut untuk mencoba aplikasi:

Role: Admin

Username: Admin 

Password: admin123

Role: User

Username: user

Password: user123

👥 Anggota Kelompok


[Aditya Dwi Aryanto]  [103132400027]

[Fauzi Romadhoni]  [103132400025]

[Khairun Fahmi]  [103132400035]
