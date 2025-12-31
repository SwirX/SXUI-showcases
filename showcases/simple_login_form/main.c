#include <stdio.h>     // Standard I/O functions like printf
#include <string.h>    // String utilities like strlen
#include "sxui.h"      // SXUI public API

/*
    Macros are compile time constants.
    They are replaced by the preprocessor before compilation.

    We use macros here because these values never change at runtime
    and because this is the traditional C way to define fixed constants.
*/
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 720

/*
    AppState groups all UI elements that need to be accessed
    across different parts of the program.

    In C, callbacks do not magically know about your variables.
    Storing pointers to UI elements inside a struct solves that problem.
*/
typedef struct AppState {
    UIElement* username_input;
    UIElement* password_input;
} AppState;

/*
    Single global application state.

    Static limits the visibility of this variable to this file only.
    This avoids accidental access from other translation units.
*/
static AppState app;

/*
    Callback triggered when the "Toggle Password" button is clicked.

    The parameter exists because SXUI callbacks share a common signature.
    We do not need it here, so we explicitly ignore it.
*/
void toggle_password(void* el) {
    (void)el;

    /*
        UI elements use flags to store state.
        Flags are bit fields packed into a single integer.

        We read the current flags, flip the password flag,
        then apply the new value back to the element.
    */
    int flags = sxui_get_flags(app.password_input);
    int new_flags = flags ^ UI_FLAG_PASSWORD;
    sxui_set_flags(app.password_input, new_flags);
}

/*
    Callback triggered when the "Login" button is clicked.
*/
void login(void* el) {
    (void)el;

    /*
        sxui_get_text returns a pointer to a null terminated C string.
        We do not own this memory and should not modify it.
    */
    char* username = (char*)sxui_get_text(app.username_input);
    char* password = (char*)sxui_get_text(app.password_input);

    /*
        Validation logic:

        - Check that the pointer is not NULL
        - Check that the first character is not '\0'

        '\0' is the null terminator in C.
        If the first character is '\0', the string is empty.
    */
    if (username && username[0] != '\0' &&
        password && password[0] != '\0') {

        /*
            Never print passwords in plaintext.
            Even in demos, it is better to model safe behavior.
        */
        printf(
            "\nLogin Attempt:\nUsername: %s\nPassword length: %zu characters\n",
            username,
            strlen(password)
        );
    } else {
        printf("\nLogin Failed: Username or Password cannot be empty!\n");
    }
}

int main() {
    /*
        Initialize SXUI.

        Parameters:
        - Window title
        - Window width
        - Window height
        - Seed color used for theming
    */
    sxui_init("Simple Login Form", WINDOW_WIDTH, WINDOW_HEIGHT, 0xFF5A5AFF);

    /*
        Dimensions of the login form container.
    */
    int form_w = 300;
    int form_h = 350;

    /*
        Root frame for the login form.

        Passing NULL as the parent makes this a top level element.
        Position is calculated to center the form in the window.
    */
    UIElement* login_form_bg =
        sxui_frame(
            NULL,
            (WINDOW_WIDTH - form_w) / 2,
            (WINDOW_HEIGHT - form_h) / 2,
            form_w,
            form_h,
            UI_FLAG_NONE
        );

    /*
        Spacer frame used for vertical padding.
        Frames are often used purely for layout.
    */
    sxui_frame(login_form_bg, 0, 0, form_w - 24, 20, UI_FLAG_NONE);

    /*
        Title label.
    */
    UIElement* login_form_welcoming = sxui_label(login_form_bg, "Welcome Back!");
    sxui_set_size(login_form_welcoming, form_w, 24);

    /*
        Subtitle label.
    */
    UIElement* login_form_text = sxui_label(login_form_bg, "Login into your account");
    sxui_set_size(login_form_text, form_w, 24);

    /*
        Spacer before input fields.
    */
    sxui_frame(login_form_bg, 0, 0, form_w - 24, 50, UI_FLAG_NONE);

    /*
        Username input field.

        The returned pointer is stored in AppState
        so callbacks can access it later.
    */
    app.username_input = sxui_input(login_form_bg, "Enter Your Username", 0);
    sxui_set_size(app.username_input, form_w - 24, 30);

    /*
        Password input field.

        The last parameter enables password masking.
    */
    app.password_input = sxui_input(login_form_bg, "Enter Your Password", 1);
    sxui_set_size(app.password_input, form_w - 24, 30);

    /*
        Button that toggles password visibility.
        The callback is bound directly at creation time.
    */
    UIElement* login_password_toggle =
        sxui_button(login_form_bg, "Toggle Password", toggle_password);
    sxui_set_size(login_password_toggle, form_w - 24, 22);

    /*
        Login button.

        This demonstrates explicit binding of callbacks
        after the element has been created.
    */
    UIElement* login_button = sxui_button(login_form_bg, "Login", NULL);
    sxui_set_size(login_button, 150, 25);
    sxui_set_position(login_button, (form_w - 150) / 2, form_h - 50);
    sxui_on_click(login_button, login);

    /*
        Main event loop.

        This loop:
        - Processes input
        - Updates UI state
        - Renders everything

        The application exits when the window is closed.
    */
    while (!sxui_should_quit()) {
        sxui_poll_events();
        sxui_render();
    }

    /*
        Clean shutdown.
        Always free resources explicitly in C.
    */
    sxui_cleanup();
    return 0;
}
