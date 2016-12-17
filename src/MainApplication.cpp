#include "MainApplication.h"
#include "MainWindow.h"

MainApplication::MainApplication()
	:Gtk::Application("nf.co.dagal.dagalide")
{
	Glib::set_application_name("Dagal IDE");
}

Glib::RefPtr<MainApplication> MainApplication::create()
{
	return Glib::RefPtr<MainApplication>(new MainApplication());
}

