#include <stdio.h>
#include "sxui.h"
#include "dynamic_list.h"

int WIDTH = 1200;
int HEIGHT = 720;

int main() {
    sxui_init("Simple Login Form", WIDTH, HEIGHT, 0xFF5A5AFF);

    int form_w = 300;
    int form_h = 350;
    UIElement* login_form_bg = sxui_frame(NULL, (WIDTH-form_w)/2, (HEIGHT-form_h)/2, form_w, form_h, UI_FLAG_NONE);

    sxui_frame(login_form_bg, 0, 0, form_w-24, 20, UI_FLAG_NONE);

    UIElement* login_form_welcoming = sxui_label(login_form_bg, "Welcome Back!");
    sxui_set_size(login_form_welcoming, form_w, 24);

    UIElement* login_form_text = sxui_label(login_form_bg, "Login into your account");
    sxui_set_size(login_form_text, form_w, 24);

    sxui_frame(login_form_bg, 0, 0, form_w-24, 50, UI_FLAG_NONE);
    
    UIElement* login_username_input = sxui_input(login_form_bg, "Enter Your Username", 0);
    sxui_set_size(login_username_input, form_w-24, 30);

    UIElement* login_password_input = sxui_input(login_form_bg, "Enter Your Password", 1);
    sxui_set_size(login_password_input, form_w - 24, 30);
    
    UIElement* login_password_toggle = sxui_button(login_form_bg, "Toggle Password", NULL);
    sxui_set_size(login_password_toggle, form_w - 24, 22);

    UIElement* login_button = sxui_button(login_form_bg, "Login", NULL);
    sxui_set_size(login_button, 150, 25);
    sxui_set_position(login_button, (form_w-150)/2, form_h-50);

    while(!sxui_should_quit()) {
        sxui_poll_events();
        sxui_render();
    }

    sxui_cleanup();
    return 0;
}
