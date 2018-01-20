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
	Gtk::ScrolledWindow *m_scrollwindow;
	Gtk::Label *m_label;
	MatWidget *mat_widget;
	cv::Mat image;
};


#endif
