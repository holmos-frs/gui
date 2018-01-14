#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <gtkmm-3.0/gtkmm.h>
#include "ApplicationWindow.h"

class Application : public Gtk::Application {
protected:
	Application();

public:
	static Glib::RefPtr<Application> create();

protected:
	void on_activate() override;

private:
	ApplicationWindow* create_appwindow();
	void on_hide_window(Gtk::Window* window);
};

#endif
