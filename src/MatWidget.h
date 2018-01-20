#ifndef MATWIDGET_H_
#define MATWIDGET_H_

#include <gtkmm-3.0/gtkmm.h>
#include <cairomm-1.0/cairomm/cairomm.h>
#include <opencv2/opencv.hpp>

class MatWidget : public Gtk::ScrolledWindow {
public:
	MatWidget(cv::Mat *image);
	void on_alloc(Gtk::Allocation& t);
	virtual ~MatWidget();
private:
	int width = 0, height = 0;
	float image_aspect;
	cv::Mat *image;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf;
	Gtk::Image *image_widget;
	Gtk::AspectFrame *aspect_frame;
};

#endif
