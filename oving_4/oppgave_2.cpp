#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label firstname_label;
  Gtk::Entry firstname;
  Gtk::Label lastname_label;
  Gtk::Entry lastname;
  Gtk::Button button;
  Gtk::Label output;

  Window() {
    set_title("Øving 4");

    firstname_label.set_label("First name");
    lastname_label.set_label("Last name");
    button.set_label("Combine names");
    button.set_sensitive(false);

    vbox.pack_start(firstname_label);
    vbox.pack_start(firstname);
    vbox.pack_start(lastname_label);
    vbox.pack_start(lastname);
    vbox.pack_start(button);
    vbox.pack_start(output);

    add(vbox);  // Add vbox to window
    show_all(); // Show all widgets

    auto check_empty_lambda = [this]() {
      if (firstname.get_text_length() == 0 || lastname.get_text_length() == 0) {
        button.set_sensitive(false);
      } else {
        button.set_sensitive(true);
      }
    };

    firstname.signal_changed().connect(check_empty_lambda);
    lastname.signal_changed().connect(check_empty_lambda);

    button.signal_clicked().connect([this]() {
      output.set_text("Names combined: " + firstname.get_text() + " " + lastname.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
