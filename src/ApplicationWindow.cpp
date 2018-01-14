#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow() {
	set_default_size(1024, 720);
	set_title("HolMOS GUI");

	grid_container.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

	mat_widget = new MatWidget();
	m_label = new Gtk::Label("Hello World");

	grid_container.add(*m_label);
	grid_container.add(*mat_widget);

	for(int i=0; i<1024*5*3; i++)
		mat_widget->image->at<char>(i) = 100;

	add(grid_container);

	show_all_children();
}

ApplicationWindow::~ApplicationWindow() {
	delete m_label;
	delete mat_widget;
}
