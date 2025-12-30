#include <stdio.h>
#include "sxui.h"
#include "dynamic_list.h"

int WIDTH = 1200;
int HEIGHT = 720;

int main() {
    sxui_init("Simple Login Form", WIDTH, HEIGHT, 0xFF5A5AFF);

    UIElement* hello_world = sxui_label(NULL, "Hello World!");
    sxui_set_position(hello_world, 50, 10);

    while(!sxui_should_quit()) {
        sxui_poll_events();
        sxui_render();
    }

    sxui_cleanup();
    return 0;
}
