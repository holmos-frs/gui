#ifndef MATWIDGET_H_
#define MATWIDGET_H_

#include <gtkmm.h>

class MatWidget : public Gtk::DrawingArea {
public:
	MatWidget();
	virtual ~MatWidget();
protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

};

#endif
