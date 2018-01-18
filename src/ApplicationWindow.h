#ifndef APPLICATION_WINDOW_H_
#define APPLICATION_WINDOW_H_

#include <gtkmm-3.0/gtkmm.h>
#include <opencv2/opencv.hpp>
#include "MatWidget.h"

class ApplicationWindow : public Gtk::ApplicationWindow {

public:
	ApplicationWindow();
	virtual ~ApplicationWindow();

private:
	Gtk::Grid grid_container;
	Gtk::Paned main_paned;     //horizontal
	Gtk::Paned control_pained; //vertikal
	Gtk::Label *m_label;
	Gtk::Label *m_label2;
	MatWidget *mat_widget;
	cv::Mat image;
};


#endif
