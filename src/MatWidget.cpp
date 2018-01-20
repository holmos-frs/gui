#include "MatWidget.h"

MatWidget::MatWidget(cv::Mat *m_image) : Gtk::ScrolledWindow() {
	assert(sizeof(guint8) == sizeof(unsigned char));
	std::cout << "image type " << m_image->type() << std::endl;
	assert(m_image->type() == CV_8UC3);

	image_widget = new Gtk::Image();
	image_widget->set_hexpand(true);
	image_widget->set_vexpand(true);

	image = m_image;
	pixbuf = Gdk::Pixbuf::create_from_data(
	    reinterpret_cast<guint8*>(image->data),
	    Gdk::Colorspace::COLORSPACE_RGB,
	    false, 8,
	    image->cols, image->rows, image->cols * 3);
	width = image->cols;
	height = image->rows;
	image_aspect = width / float(height);

	image_widget->set(pixbuf);

	aspect_frame = new Gtk::AspectFrame();
	aspect_frame->set_shadow_type(Gtk::SHADOW_NONE);
	aspect_frame->set(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER, image_aspect);
	aspect_frame->add(*image_widget);

	add(*aspect_frame);

	signal_size_allocate().connect(sigc::mem_fun(this, &MatWidget::on_alloc));
}

void MatWidget::on_alloc(Gtk::Allocation& t) {
    int new_width, new_height;
    if((t.get_width() - width) < (t.get_height() - height)) {
	new_width = t.get_width();
	new_height = new_width / image_aspect;
    } else {
	new_height = t.get_height();
	new_width = new_height * image_aspect;
    }
    
	
    image_widget->set(
	    pixbuf->scale_simple(new_width, new_width, Gdk::INTERP_NEAREST)
	    );
}

MatWidget::~MatWidget() {
}
