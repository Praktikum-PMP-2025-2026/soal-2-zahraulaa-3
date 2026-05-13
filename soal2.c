// EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
// Modul               : 5
// Hari dan Tanggal    : Rabu, 13 Mei 2026
// Nama (NIM)          : Zahra Aulia (13224007)
// Nama File           : soal2.c
// Deskripsi           : Program mengelompokkan pulau berdasarkan daerah aktif pada graph/matriks yang dibuat. Kemudian program akan menghitung jumlah set matriks yang secara vertikal atau horizontal memiliki sesama daerah aktif kemudian mendisplaynya pada "ISLANDS x" yaitu jumlah pulau. Program juga akan menampilkan ukuran pulau yaitu banyak elemen 1 pada pulau tersebut, program emmilih pulau terbesar lalu menampilkannya pada "LARGEST y" dengan y adalah jumlah elemen 1 di pulau terbesar. Jika tidak ada pulau yang terbentuk, program akan menampilkan "ISLANDS 0" dan "LARGEST 0"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100
char matrix[MAXN][MAXN];
int nrows, ncols;

// fungsi dfs - ambil dari stackexchange
int dfs(char matrix[MAXN][MAXN], int r, int c, int nrows, int ncols) {
    if (r < 0 || r >= nrows || c < 0 || c >= ncols || matrix[r][c] == '0') {
        return 0;
    }

// buat cek elemen - ambil dari stackexchange
    matrix[r][c] = '0';
    int size = 1;
    size += dfs(matrix, r + 1, c, nrows, ncols); // bawah
    size += dfs(matrix, r - 1, c, nrows, ncols); // atas
    size += dfs(matrix, r, c + 1, nrows, ncols); // kanan
    size += dfs(matrix, r, c - 1, nrows, ncols); // kiri

    return size;
}

int main() {
// ambil dari stackoverflow
    char matrix[MAXN][MAXN];
    int nrows, ncols;

    if (scanf("%d %d", &nrows, &ncols) != 2) return 1;
    for (int i = 0; i < nrows; i++) {
        scanf("%s", matrix[i]);
    }

    // buat print matrix
    // for (i = 0; i < nrows; i++) {
    //     printf("%s\n", mat[i]);
    // }
    // return 0;

// islands ambil dari stackexchange
// largest ambil dari geeksforgeeks
    int islands = 0;
    int largest = 0;

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (matrix[i][j] == '1') {
                islands++;
                int temp = dfs(matrix, i, j, nrows, ncols);
                    if (temp > largest) {
                        largest = temp;
                }
            }
        }
    }

    printf("ISLANDS %d\n", islands);
    printf("LARGEST %d\n", largest);

    return 0;
}

// bikin matrix : https://stackoverflow.com/questions/2776397/create-a-basic-matrix-in-c-input-by-user
    // Source - https://stackoverflow.com/a/2776452
    // Posted by Jacob
    // Retrieved 2026-05-13, License - CC BY-SA 2.5
    // Source - https://stackoverflow.com/q/2776397
    // Posted by NLed, modified by community. See post 'Timeline' for change history
    // Retrieved 2026-05-13, License - CC BY-SA 3.0
// fungsi dfs dan islands : https://cs.stackexchange.com/questions/93202/dfs-and-bfs-time-and-space-complexities-of-number-of-islands-on-leetcode
// caru largest : https://www.geeksforgeeks.org/dsa/find-length-largest-region-boolean-matrix/
