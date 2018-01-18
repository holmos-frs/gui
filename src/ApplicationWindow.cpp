#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow() {
	set_default_size(1024, 720);
	set_title("HolMOS GUI");


	grid_container.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

	main_paned = Gtk::Paned(Gtk::ORIENTATION_HORIZONTAL);
	control_pained = Gtk::Paned(Gtk::ORIENTATION_VERTICAL);


	//mat_widget = new MatWidget(&image);

	m_label = new Gtk::Label("bilder");
	m_label2 = new Gtk::Label("Steuerung");

	control_pained.add2(*m_label2);

	main_paned.add1(*m_label);
	main_paned.add2(control_pained);

	int new_pos = 1024 / 3;
	std::cout << " New pos: " << new_pos << std::endl;
	main_paned.set_position(new_pos);
	//grid_container.add(*mat_widget);


	add(main_paned);
	//add(paned2);

	show_all_children();
}

ApplicationWindow::~ApplicationWindow() {
	delete m_label;
	delete mat_widget;
}
