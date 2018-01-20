#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow() {
	set_default_size(1024, 720);
	set_title("HolMOS GUI");

	grid_container.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

	image = cv::imread("holmos_raw.png", 1);
	std::cout << "image type " << image.type() << std::endl;
	mat_widget = new MatWidget(&image);
	m_scrollwindow = new Gtk::ScrolledWindow();
	m_scrollwindow->add(*mat_widget);

	m_label = new Gtk::Label("Hello World");

	grid_container.add(*m_label);
	grid_container.add(*m_scrollwindow);

	add(grid_container);

	show_all_children();
}

ApplicationWindow::~ApplicationWindow() {
	delete m_label;
	delete mat_widget;
}
