#include "video_mode13h.h"
#include "graphics.h"
#include "window.h"
#include "button.h"

void gui_start() {
    set_video_mode_13h();
    fill_rect(0, 0, 320, 200, 0x1F);         // خلفية سطح المكتب
    draw_window(30, 30, 200, 100, "Welcome");
    draw_button(50, 80, 80, 20, "Click Me");
}
