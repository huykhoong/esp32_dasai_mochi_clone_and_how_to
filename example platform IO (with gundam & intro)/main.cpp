#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h> 

// INCLUDE file gif tạo từ webapp vô đây
#include "daichi_gundam.h"
#include "daichi_intro.h"

// Cấu hình màn hình
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Hàm vẽ GIF (có trong github của tác giả)
void playGIF(const AnimatedGIF* gif, uint16_t loopCount = 1) {
  for (uint16_t loop = 0; loop < loopCount; loop++) {
    for (uint8_t frame = 0; frame < gif->frame_count; frame++) {
      // Xóa buffer trước khi vẽ
      u8g2.clearBuffer();

      // Vẽ từng pixel
      for (uint16_t y = 0; y < gif->height; y++) {
        for (uint16_t x = 0; x < gif->width; x++) {
          uint16_t byteIndex = y * (((gif->width + 7) / 8)) + (x / 8);
          uint8_t  bitIndex  = 7 - (x % 8);
          if (gif->frames[frame][byteIndex] & (1 << bitIndex)) {
            u8g2.drawPixel(x, y);
          }
        }
      }

      // Đẩy buffer ra màn hình
      u8g2.sendBuffer();

      // Chờ theo delay của khung
      delay(gif->delays[frame]);
    }
  }
}


void setup(void) {
    Serial.begin(115200);
    u8g2.begin();
    
    u8g2.sendBuffer(); 
}

void loop(void) {
    playGIF(&daichi_intro_gif, 1);
    playGIF(&daichi_gundam_gif, 1);
}