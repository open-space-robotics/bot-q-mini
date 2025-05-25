# リポジトリテンプレート

[![README in English](https://img.shields.io/badge/English-d9d9d9)](./README.md)
[![日本語版 README](https://img.shields.io/badge/日本語-d9d9d9)](./README_JA.md)

![GitHub contributors](https://img.shields.io/github/contributors/SpaceData-Inc/temp_rep)
![GitHub issues](https://img.shields.io/github/issues/SpaceData-Inc/temp_rep)
![GitHub fork](https://img.shields.io/github/forks/SpaceData-Inc/temp_rep)
![GitHub stars](https://img.shields.io/github/stars/SpaceData-Inc/temp_rep)

![SD Robot](img/bot_q_mini.jpg)


## 目次
1. [**タイトル A**](#タイトル-a)
    1. [サブタイトル A1](#サブタイトル-a1)
    2. [サブタイトル A2](#サブタイトル-a2)

2. [**タイトル B**](#タイトル-b)
    1. [サブタイトル B1](#サブタイトル-b1)
    2. [サブタイトル B2](#サブタイトル-b2)

3. [**タイトル C**](#タイトル-c)
    1. [サブタイトル C1](#サブタイトル-c1)
    2. [サブタイトル C2](#サブタイトル-c2)


## タイトル A
OOOOO.

### サブタイトル A1
OOOOO.

```
$ command
```

| Left align | Right align | Center align |
|:-----------|------------:|:------------:|
| This       | This        | This         |
| column     | column      | column       |
| will       | will        | will         |
| be         | be          | be           |
| left       | right       | center       |
| aligned    | aligned     | aligned      |

#### 参考
- [GitHub Flavored Markdown Spec](https://github.github.com/gfm/#introduction)
- [Markdown記法 チートシート](https://qiita.com/Qiita/items/c686397e4a0f4f11683d)

### サブタイトル A2
OOOOO.


## タイトル B
OOOOO.

### サブタイトル B1
OOOOO.

### サブタイトル B2
OOOOO.


## タイトル C
OOOOO.

### サブタイトル C1
OOOOO.

### サブタイトル C2
OOOOO.

<!--
Waveshare RP2040-LCD-1.28のセットアップ
Waveshare RP2040-LCD-1.28という円形LCD + マイコンの装置を用いる．
PowerPointで表情のモーションを作る関係上，全てWindowsでの開発を前提としている．
環境セットアップと使い方については下記のリンクを参照．
https://www.waveshare.com/wiki/RP2040-LCD-1.28
https://cotechworks.ltt.jp/2024/04/17/post-1463/
Q mini の表情の作成と読み込み
パワーポイントのアニメーション機能で表情を作成．
480 × 480の最低画質でmp4の動画として出力．
Windowsのコマンドプロンプトを管理者権限で開き，下記のコマンドを実行し，動画処理ツールをインストール．
$ winget install --id=Gyan.FFmpeg -e
下記のコマンドで動画をbmp形式の画像群に変換 (importファイル名，30fps，240×240pixel，4桁連番のexportファイル名を指定)．
$ ffmpeg -i face_blink.mp4 -vf "fps=30,scale=240:240" frame%04d.bmp
下記のコマンドでbmp形式の画像群をヘッダー情報等を除いたrawデータ群に変換 (1~6に対しての繰り返し処理，importファイル名，exportファイル名を指定)
$ for %i in (1 2 3 4 5 6) do ffmpeg -i frame000%i.bmp -f rawvideo -pix_fmt rgb565 frame000%i.raw
Gitの入った環境で下記のコマンドを実行し，フレームデータのヘッダーファイルを作成する．これをrawデータのファイル数だけ繰り返す．
$ xxd -i frame0001.raw > frame1.h
その後，各ヘッダーファイルを下記の形式に書き直す．
#pragma once 
#include <Arduino.h>
const uint8_t frame1[] PROGMEM = {
  0x1F, 0x7C, 0x00, 0xFF, ..., // データたくさん
};
あとは，メインコードで作成したヘッダファイルを描画し，理想の表情ができるまで微調整．
-->
---

[トップに戻る](#リポジトリテンプレート)
