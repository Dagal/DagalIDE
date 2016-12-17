#include "MainWindow.h"
#include <iostream>

#include <gtkmm/main.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/stock.h>

MainWindow::MainWindow() :
	Gtk::ApplicationWindow(),
	mMainBox(),
	mMainHeader(),
	mMainMenu(),
	mMainToolbar(),
	mButton("Hello World"),
	mMainStatusBar()
{
	// Barre de titre personnalisée.
	mMainHeader.set_title("Dagal IDE");
	mMainHeader.set_show_close_button(true);
	set_titlebar(mMainHeader);
	set_hide_titlebar_when_maximized(true);

	// Boîte verticale principale
	mMainBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
	add(mMainBox);

	// Menu principal
	Glib::RefPtr<Gtk::Action> actionNouveau =
		Gtk::Action::create("nouveau", Gtk::Stock::NEW);
	Glib::RefPtr<Gtk::Action> actionQuitter =
		Gtk::Action::create("quitter",
												Gtk::Stock::QUIT,
												"Quitter l’application",
												"Ferme l’application");
	Gtk::Menu menuFichier;
	menuFichier.append(*(actionNouveau->create_menu_item()));
	menuFichier.append(*(actionQuitter->create_menu_item()));

	Gtk::MenuItem menuItemFichier("Fichier");
	menuItemFichier.set_submenu(menuFichier);

	Gtk::MenuBar barreMenu;
	barreMenu.append(menuItemFichier);

	set_app_menu(barreMenu);

	actionQuitter->signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));

	// Création de la Toolbar
	mMainBox.pack_start(mMainToolbar, Gtk::PACK_SHRINK);

	// Création d'un bouton temporaire.
	mButton.signal_clicked().connect(sigc::mem_fun(*this,
		&MainWindow::on_button_clicked));
	mMainBox.pack_start(mButton);

	// Création de la barre de status.
	mMainBox.pack_end(mMainStatusBar,Gtk::PACK_SHRINK);

	// The final step is to display this newly created widget...
	show_all();

	mMainStatusBar.push("Création de la fenêtre principale terminée.");
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_button_clicked()
{
  std::cout << "Hello World" << std::endl;
}
