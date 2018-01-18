#include "MatWidget.h"

MatWidget::MatWidget(cv::Mat *m_image) : Gtk::Image() {
	assert(sizeof(guint8) == sizeof(unsigned char));
	std::cout << "image type " << m_image->type() << std::endl;
	assert(m_image->type() == CV_8UC3);
	set_hexpand(true);
	set_vexpand(true);

	image = m_image;
	pixbuf = Gdk::Pixbuf::create_from_data(
	    reinterpret_cast<guint8*>(image->data),
	    Gdk::Colorspace::COLORSPACE_RGB,
	    false, 8,
	    image->cols, image->rows, image->cols * 3);

	set(pixbuf);
}

MatWidget::~MatWidget() {

}
