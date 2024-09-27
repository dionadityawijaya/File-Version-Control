# Simple File Version Control System

## Deskripsi
Proyek ini adalah sistem version control sederhana yang memungkinkan pengguna untuk melakukan commit, rollback, branching, dan merging pada file teks. 

## Fitur
- **Commit dan Rollback**: Simpan dan kembalikan versi file.
- **Branching dan Merging**: Kelola perubahan dari cabang yang berbeda.
- **Conflict Resolution**: Atasi konflik pada saat penggabungan perubahan.

## Cara Menggunakan
1. Buat commit dengan menambahkan perubahan pada file.
2. Gunakan rollback untuk mengembalikan ke versi sebelumnya.
3. Branching memungkinkan membuat cabang baru untuk perubahan terpisah.
4. Merging menggabungkan perubahan dari cabang ke cabang utama.

## Build dan Jalankan
Gunakan perintah berikut untuk membangun dan menjalankan proyek:
```bash
./file_version_control

Untuk compile file main, jalankan :
  g++ -std=c++17 -Iinclude src/*.cpp -o a.exe 


Untuk compile tests, jalankan :
g++ -std=c++17 -Iinclude src/version_control.cpp tests/*.cpp -o a.exe 
