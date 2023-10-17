#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Entry entry1;
    Gtk::Entry entry2;
    Gtk::Button button;
    Gtk::Label label;
    Gtk::Label firstName;
    Gtk::Label lastName;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Click");

        firstName.set_text("Firstname:");
        lastName.set_text("Lastname:");

        box.pack_start(firstName);
        box.pack_start(entry1);
        box.pack_start(lastName);
        box.pack_start(entry2);
        box.pack_start(button);
        box.pack_start(label);

        add(box);   // Add vbox to window
        show_all(); // Show all widgets

        button.set_sensitive(false);

        entry1.signal_changed().connect([this]() {
            buttonSensitiveState();
        });

        entry2.signal_changed().connect([this] () {
            buttonSensitiveState();
        });

        button.signal_clicked().connect([this]() {
            label.set_text("Button was clicked");
        });
    }

    void buttonSensitiveState() {
        bool entriesFilled = !firstName.get_text().empty() && !lastName.get_text().empty();
        button.set_sensitive(entriesFilled);
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}

