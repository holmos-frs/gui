#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow() {
	set_default_size(1024, 720);
	set_title("HolMOS GUI");

	grid_container.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

	image = cv::imread("holmos_raw.png", 0);
	//mat_widget = new MatWidget(&image);

	m_label = new Gtk::Label("Hello World");

	grid_container.add(*m_label);
	//grid_container.add(*mat_widget);

	add(grid_container);

	show_all_children();
}

ApplicationWindow::~ApplicationWindow() {
	delete m_label;
	delete mat_widget;
}
