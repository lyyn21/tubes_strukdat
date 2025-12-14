# 🎵 Console Music Player

**Tugas Besar Mata Kuliah Struktur Data (CDK2AAB4)**
Semester Ganjil 2025/2026

---

## 📌 Deskripsi Singkat

**Console Music Player** adalah aplikasi pemutar musik berbasis **Command Line Interface (CLI)** yang mensimulasikan sistem backend pemutar musik modern. Proyek ini dibuat untuk menunjukkan penerapan **struktur data** dalam pengelolaan lagu secara efisien.

Aplikasi memiliki dua peran pengguna:

* **Admin** → Mengelola data lagu
* **User** → Menikmati musik (play, playlist, queue, dll)

---

## 🧠 Struktur Data yang Digunakan

Aplikasi ini menggunakan **3 struktur data utama** sesuai ketentuan tugas besar:

### 1. Doubly Linked List (Library & Playlist)

* Menyimpan daftar lagu dan playlist
* Mendukung navigasi **Next / Previous**
* Efisien untuk hapus/tambah lagu di tengah list

### 2. Stack (History Pemutaran)

* Menyimpan riwayat lagu yang sudah diputar
* Menggunakan prinsip **LIFO (Last In First Out)**

### 3. Queue (Antrian Lagu)

* Menyimpan lagu yang diprioritaskan untuk diputar berikutnya
* Menggunakan prinsip **FIFO (First In First Out)**

---

## ✨ Fitur Utama

* 🎶 **Play Music** (Library & Playlist)
* ⏭️ **Smart Next Song Logic**

  * Putar Queue jika ada
  * Jika tidak, lanjut ke Playlist
  * Mode Library: rekomendasi genre → artis
* 📜 **Riwayat Pemutaran (History)**
* 📥 **Add to Queue**
* 🔍 **Search Lagu** (Sequential Search)
* 🔃 **Sorting Lagu** (Bubble Sort)

  * Berdasarkan Judul (A–Z)
  * Berdasarkan Tahun Rilis
* 📊 **Tampilan Tabel Rapi** (menggunakan `<iomanip>`)

---

## 📂 Struktur File

Proyek dibuat secara **modular** agar kode rapi dan mudah dipahami:

| File               | Deskripsi                           |
| ------------------ | ----------------------------------- |
| `music_player.h`   | Deklarasi struct & class            |
| `music_player.cpp` | Implementasi logika & struktur data |
| `main.cpp`         | Menu, login, dan alur program       |

---

## ⚙️ Cara Menjalankan Program

### Prasyarat

* Compiler C++ (G++ / MinGW)

### Langkah-langkah

1. **Clone Repository**

```bash
git clone https://github.com/lyyn21/tubes_strukdat.git
cd tubes_strukdat
```

2. **Compile Program**

```bash
g++ main.cpp music_player.cpp -o music_app
```

> ⚠️ Jangan hanya compile `main.cpp`, karena akan terjadi error linker.

3. **Jalankan Aplikasi**

**Windows**

```bash
music_app.exe
```

**Linux / Mac**

```bash
./music_app
```

---

## 🔐 Akun Demo

| Role  | Username | Password | Akses                                  |
| ----- | -------- | -------- | -------------------------------------- |
| Admin | admin    | admin123 | CRUD lagu, sorting library             |
| User  | user     | user123  | Play, playlist, queue, history, search |

> Ketik **`exit`** pada username untuk keluar dari aplikasi.

---

## 👥 Anggota Kelompok 11

* Fauzi Romadhoni — 103132400025
* Aditya Dwi Aryanto — 103132400027
* Khairun Fahmi — 103132400035

---

## 📝 Catatan

Proyek ini dibuat **khusus untuk keperluan akademik** sebagai evaluasi mata kuliah **Struktur Data**.
