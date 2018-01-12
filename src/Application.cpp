#include "Application.h"

Application::Application()
: Gtk::Application("org.frsem.holmos", Gio::APPLICATION_HANDLES_OPEN) {
}

Glib::RefPtr<Application> Application::create() {
	return Glib::RefPtr<Application>(new Application());
}

ApplicationWindow* Application::create_appwindow() {
	auto appwindow = new ApplicationWindow();

	add_window(*appwindow);

	//appwindow->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this, &Application::on_hide_window), appwindow));

	return appwindow;
}

void Application::on_activate() {
	auto appwindow = create_appwindow();
	appwindow->present();
}

void Application::on_hide_window(Gtk::Window* window) {
	delete window;
}
