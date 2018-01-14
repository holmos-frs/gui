#ifndef MATWIDGET_H_
#define MATWIDGET_H_

#include <gtkmm-3.0/gtkmm.h>
#include <cairomm-1.0/cairomm/cairomm.h>
#include <opencv2/opencv.hpp>

class MatWidget : public Gtk::Image {
public:
	MatWidget(cv::Mat *image);
	virtual ~MatWidget();
private:
	int width = 0, height = 0;
	cv::Mat *image;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf;

};

#endif
