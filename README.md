[ENGLISH] This project is a clone of Dasai Mochi, the adorable animated character made popular on YouTube. Designed to run on the ESP32 microcontroller, the system renders animated emotes on a TFT display by converting GIFs to C++ code using the powerful tool gif2cpp.


• Project highlights:
 ◦ Displaying animated Mochi emotes on oled screen
 ◦ Using gif2cpp (https://huykhong.com/IOT/gif2cpp) to convert GIFs into lightweight C++ arrays
 ◦ Built on ESP32 
 ◦ Runs smooth 15 FPS animations on ILI9341 / ST7789 displays
 ◦ Ideal for robotic expressions, smart assistants, or pure cuteness


• What is gif2cpp?
https://huykhong.com/IOT/gif2cpp
gif2cpp is an open-source tool that converts animated GIFs into C++ header files – perfect for embedding animations in microcontroller projects where you can't use real-time video formats.


• How to use:
Tutorial in my tiktok 
 1. Extract emote sections using ffmpeg:
  → ffmpeg -ss ... -to ... -i full.mp4 ... -y emote.gif
 2. Run gif2cpp to generate .h file
 3. Include in your ESP32 project.


• Original Video Credit:
🎥 Dasai! Mochi Gen 2 All Emotes (almost)
→ All emotes are inspired and extracted from this video. Full image rights belong to the original creator.


[VIETNAMESE]
• Coi vid tiktok của tôi
