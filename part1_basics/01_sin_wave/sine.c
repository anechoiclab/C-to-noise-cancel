/*
* 第1部　第1回 : 配列にサイン波を作る
* 無響ラボ　note連載 「Cの基礎からノイズキャンセルまで」
*
* コンパイル : gcc sine.c -o sine.out -lm
* 実行 : ./sine.out > sine.csv
*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
/*サンプリング周波数[Hz] FS : 1秒間に何回値を取るか*/
#define FS 1000 
/*サンプル数 (FSと同じなので1秒分)*/
#define N 1000

int main(void)
{
    /*信号を入れる配列*/
    double signal[N];
    /*サイン波の周波数[Hz]*/
    double f = 5.0; 
    /*サイン波の振幅*/
    double A = 1.0;

    /*各サンプル時刻　t = n/FS (t: 0 → 1)での値を計算して配列に入れる*/

    for(int n=0; n < N; n++){
        /*intで宣言したnを浮動小数で計算するために(double)でキャストする*/
        double t = (double)n / FS;
        signal[n] = A * sin(2.0 * PI * f * t);
    }

    /*csv形式(時刻、振幅)で出力する*/
    printf("t,x\n");
    for(int n=0; n < N; n++){
        printf("%f,%f\n", (double)n / FS, signal[n]);
    }

    return 0;
}