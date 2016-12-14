#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm/applicationwindow.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/box.h>
#include <gtkmm/menu.h>
#include <gtkmm/button.h>
#include <gtkmm/toolbar.h>
#include <gtkmm/statusbar.h>

class MainWindow : public Gtk::ApplicationWindow
{

public:
  MainWindow();
  virtual ~MainWindow();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
	Gtk::Box mMainBox;
	Gtk::HeaderBar mMainHeader;
	Gtk::Menu mMainMenu;
	Gtk::Toolbar mMainToolbar;
  Gtk::Button mButton;
	Gtk::Statusbar mMainStatusBar;
};

#endif // GTKMM_MAINWINDOW_H
