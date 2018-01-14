#ifndef APPLICATION_WINDOW_H_
#define APPLICATION_WINDOW_H_

#include <gtkmm-3.0/gtkmm.h>
#include "MatWidget.h"

class ApplicationWindow : public Gtk::ApplicationWindow {

public:
	ApplicationWindow();
	virtual ~ApplicationWindow();

private:
	Gtk::Grid grid_container;
	Gtk::Label *m_label;
	MatWidget *mat_widget;
};


#endif
