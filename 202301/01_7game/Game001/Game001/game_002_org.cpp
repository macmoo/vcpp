﻿// [1]ヘッダーをインクルードする場所

#include <stdio.h>  // [1-1]標準入出力ヘッダーをインクルードする
#include <stdlib.h> // [1-2]標準ライブラリヘッダーをインクルード
#include <string.h> // [1-3]文字列操作ヘッダーをインクルードする
#include <time.h>   // [1-4]時間管理ヘッダーをインクルードする
#include <conio.h>  // [1-5]コンソール入出力ヘッダーをインクルードする

// [2]定数を定義する場所

#define FIELD_WIDTH     (160)           // [2-1]フィールドの幅を定義する
#define FIELD_HEIGHT    (160)           // [2-2]フィールドの高さを定義する

#define FPS             (10)            // [2-3]1秒当たりの更新回数を定義する
#define INTERVAL        (1000 / FPS)    // [2-4]更新間隔（ミリ秒）を定義する

// [3]変数を宣言する場所

// [3-1]フィールドを宣言する
bool field[FIELD_HEIGHT][FIELD_WIDTH] =
{
/*
    {0,1,0},
    {0,0,1},
    {1,1,1}
*/
};

// [4]関数を宣言する場所

// [4-1]フィールドを描画する関数を宣言する
void DrawField()
{
    system("cls");// [4-1-1]描画前に画面をクリアする

    // [4-1-2]フィールドのすべての行を反復する
    for (int y = 0; y < FIELD_HEIGHT; y++)
    {
        // [4-1-3]フィールドのすべての列を反復する
        for (int x = 0; x < FIELD_WIDTH; x++)
        {
            // [4-1-4]セルが生きていれば「■」を、死んでいれば「　」を描画する
            printf("%s", field[y][x] ? "■" : "　");
        }

        printf("\n");// [4-1-5]1行描画するごとに改行する
    }
}

// [4-2]対象のセルと隣接する生きたセルの数を取得する関数を宣言する
int GetLivingCellsCount(int _x, int _y)
{
    int count = 0;// [4-2-1]生きているセルを数えるカウンターを宣言する

    // [4-2-2]対象のセルの上下1マスを反復する
    for (int y = _y - 1; y <= _y + 1; y++)
    {
/*
        // [4-2-3]上下にループさせない場合は、行が範囲内かどうかを判定する
        if ((y < 0) || (y >= FIELD_HEIGHT))
        {
            continue;// [4-2-4]範囲外の行なのでスキップする
        }
*/
        // [4-2-5]上下にループしたY座標を宣言する
        int roopedY = (FIELD_HEIGHT + y) % FIELD_HEIGHT;

        // [4-2-6]対象のセルの左右1マスを反復する
        for (int x = _x + -1; x <= _x + 1; x++)
        {
/*
            // [4-2-7]左右にループさせない場合は、列が範囲内かどうかを判定する
            if ((x < 0) || (x >= FIELD_WIDTH))
            {
                continue;// [4-2-8]範囲外の列なのでスキップする
            }
*/
            // [4-2-9]左右にループしたX座標を宣言する
            int roopedX = (FIELD_WIDTH + x) % FIELD_WIDTH;

            // [4-2-10]対象の座標が、中心のセルと同じかどうかを判定する
            if ((roopedX == _x) && (roopedY == _y))
            {
                continue;// [4-2-11]対象の座標をスキップする
            }

            // [4-2-12]対象のセルが生きていれば1を、死んでいれば0を加算する
            count += field[roopedY][roopedX];
        }
    }

    return count;// [4-2-13]生きているセルの数を返す
}

// [4-3]1ステップ分のシミュレーションを実行する関数を宣言する
void StepSimulation()
{
    // [4-3-1]次の世代のフィールドを宣言する
    bool nextField[FIELD_HEIGHT][FIELD_WIDTH] = {};

    // [4-3-2]すべての行を反復する
    for (int y = 0; y < FIELD_HEIGHT; y++)
    {
        //  [4-3-3]すべての列を反復する
        for (int x = 0; x < FIELD_WIDTH; x++)
        {
            // [4-3-4]対象のセルと隣接する、生きているセルの数を宣言する
            int livingCellCount = GetLivingCellsCount(x, y);

            // [4-3-5]隣接する生きたセルの数で分岐する
            if (livingCellCount <= 1)// [4-3-5]1個なら
            {
                // [4-3-6]対象のセルを死滅させる
                nextField[y][x] = false;
            }
            else if (livingCellCount == 2)// [4-3-7]2個なら
            {
                // [4-3-8]現状維持
                nextField[y][x] = field[y][x];
            }
            else if (livingCellCount == 3)// [4-3-9]3個なら
            {
                // [4-3-10]対象のセルを誕生／生存させる
                nextField[y][x] = true;
            }
            else// [4-3-11]4つ以上なら
            {
                // [4-3-12]対象のセルを死滅させる
                nextField[y][x] = false;
            }
        }
    }

    // [4-3-13]次のステップのフィールドを、現在のフィールドにコピーする
    memcpy(field, nextField, sizeof field);
}

// [4-4]パターンをフィールドにコピーする関数を宣言する
void PatternTransfer(
    int _destX, int _destY,
    int _srcWidth, int _srcHeight,
    bool* _pPattern)
{
    // [4-4-1]パターン内のすべての行を反復する
    for (int y = 0; y < _srcHeight; y++)
    {
        // [4-4-2]パターン内のすべての列を反復する
        for (int x = 0; x < _srcWidth; x++)
        {
            // [4-4-3]パターンをフィールドにコピーする
            field[_destY + y][_destX + x] = _pPattern[y * _srcWidth + x];
        }
    }
}

// [4-5]プログラム実行の開始点を宣言する
int main()
{
    const int patternWidth = 10;// [4-5-1]パターンの幅を宣言する
    const int patternHeight = 8;// [4-5-2]パターンの高さを宣言する

    // [4-5-3]パターンを宣言する
    bool pattern[patternHeight][patternWidth] =
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,1,1,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    // [4-5-4]パターンをフィールドの中心にコピーする
    PatternTransfer(
        FIELD_WIDTH / 2 - patternWidth / 2,     // int _destX
        FIELD_HEIGHT / 2 - patternHeight / 2,   // int _destY
        patternWidth,                           // int _srcWidth
        patternHeight,                          // int _srcHeight
        (bool*)pattern);                        // bool* _pPattern

    clock_t lastClock = clock();// [4-5-5]前回の経過時間を宣言する

    // [4-5-6]メインループ
    while (1)
    {
        clock_t newClock = clock();// [4-5-7]現在の経過時間を宣言する

        // [4-5-8]前回の経過時間から、待機時間が経過していなければ
        if (newClock < lastClock + INTERVAL)
        {
            continue;// [4-5-9]待機状態に戻る
        }

        // [4-5-10]前回経過時間を、現在の経過時間で更新する
        lastClock = newClock;

        DrawField();// [4-5-11]フィールドを描画する関数を呼び出す

//      _getch();// [4-5-12]キーボード入力を待つ

        StepSimulation();// [4-5-13]シミュレーションを進める
    }
}