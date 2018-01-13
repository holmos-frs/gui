#include "MatWidget.h"

MatWidget::MatWidget() : Gtk::DrawingArea() {
	set_size_request(200, 200);
}

MatWidget::~MatWidget() {

}

bool MatWidget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	cr->set_source_rgb(1.0, 0.0, 1.0);
	cr->rectangle(0, 0, 800, 800);
	cr->fill();

	return true;
}
