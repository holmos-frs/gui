#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <thread>
#include <gtkmm-3.0/gtkmm.h>
#include "ApplicationWindow.h"
#include "ComputationThread.h"

class Application : public Gtk::Application {
protected:
	Application();
	virtual ~Application();

public:
	static Glib::RefPtr<Application> create();

protected:
	void on_activate() override;

private:
	ApplicationWindow* create_appwindow();
	ComputationThread* computation_thread;
	void on_hide_window(Gtk::Window* window);
};

#endif
