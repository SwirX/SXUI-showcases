#include <stdio.h>
#include "sxui.h"
#include "dynamic_list.h"

int WIDTH = 1200;
int HEIGHT = 720;

int main() {
    sxui_init("Simple Login Form", WIDTH, HEIGHT, 0xFF5A5AFF);

    int form_w = 400;
    int form_h = 500;
    UIElement* login_form_bg = sxui_frame(NULL, (WIDTH-form_w)/2, (HEIGHT-form_h)/2, form_w, form_h, UI_FLAG_NONE);

    UIElement* login_form_text = sxui_label(login_form_bg, "Login");
    
    UIElement* login_username_input = sxui_input(login_form_bg, "Enter Your Username", 0);

    UIElement* login_password_input = sxui_input(login_form_bg, "Enter Your Password", 0);
    
    UIElement* login_password_toggle = sxui_button(login_form_bg, "Toggle Password", NULL);

    UIElement* login_button = sxui_button(login_form_bg, "Login", NULL);

    while(!sxui_should_quit()) {
        sxui_poll_events();
        sxui_render();
    }

    sxui_cleanup();
    return 0;
}
