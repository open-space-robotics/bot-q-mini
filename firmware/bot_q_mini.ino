#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include "LGFX.hpp"

// 各フレーム画像 (RGB565形式のRAWデータ)
#include "frame1.h"
#include "frame2.h"


// -----------------------------------
// パラメータ設定
// -----------------------------------

// パラメータ
static constexpr int image_width  = 240;
static constexpr int image_height = 240;
static constexpr int frame_count  = 2;
static LGFX lcd;

// 各フレーム画像のポインタ
const uint8_t* frames[frame_count] = {
  frame1,
  frame2
};

// 状態管理
enum PlayState {
  BASE_FRAME,
  PLAY_BLINK
};

// 変数の初期化
PlayState currentState = BASE_FRAME;
unsigned long stateStartTime = 0;
int playbackIndex            = 0;  // フレーム再生用インデックス
int playbackRepeat           = 0;  // 何回繰り返したか


// -----------------------------------
// セットアップ関数
// -----------------------------------

void setup(void) {
  lcd.init();
  lcd.setColorDepth(16);   // RGB565
  lcd.setSwapBytes(true);  // バイト順変換有効
  lcd.startWrite();        // 高速描画モード

  // 初期状態
  lcd.clear(TFT_BLACK);
  lcd.pushImage(0, 0, image_width, image_height, (const uint16_t*)frames[0]);
  stateStartTime = millis();
}


// -----------------------------------
// メイン関数
// -----------------------------------

void loop(void) {
  unsigned long now = millis();

  // ---------------------------------
  // BASE_FRAME : 5秒間何もせずframe1を表示する
  if (currentState == BASE_FRAME) {
    if (5000 <= now - stateStartTime) {
      currentState = PLAY_BLINK;
      stateStartTime = now;
      playbackIndex  = 0;
      playbackRepeat = 0;
    }
  }

  // ---------------------------------
  // PLAY_BLINK : まばたきするモーションを表示する
  else if (currentState == PLAY_BLINK) {
    static unsigned long lastFrameTime = 0;

    if (120 <= now - lastFrameTime) {  // 120[ms]
      lcd.clear(TFT_BLACK);
      lcd.pushImage(0, 0, image_width, image_height, (const uint16_t*)frames[playbackIndex]);
      playbackIndex++;

      // 1回のまばたきの終了判定
      if (frame_count <= playbackIndex) {
        playbackIndex = 0;
        playbackRepeat++;
      }

      // 2回のまばたきの終了判定
      if (2 <= playbackRepeat) {
        currentState   = BASE_FRAME;
        stateStartTime = now;

        lcd.clear(TFT_BLACK);
        lcd.pushImage(0, 0, image_width, image_height, (const uint16_t*)frames[0]);
      }

      lastFrameTime = now;
    }
  }
}