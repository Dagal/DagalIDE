#include <gtkmm.h>
#include <iostream>

Gtk::ApplicationWindow* pAW = nullptr;

static
void on_quit()
{
  if(pAW)
    pAW->hide(); //hide() will cause main::run() to end.
}

int main (int argc, char **argv)
{
  auto app = Gtk::Application::create(argc, argv, "nf.co.dagal.dagalide");

  //Load the GtkBuilder file and instantiate its widgets:
  auto refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("UserInterface/DagalIDE.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 2;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 3;
  }

  //Get the GtkBuilder-instantiated Dialog:
  refBuilder->get_widget("MainWindow", pAW);
  if(pAW)
  {
    //Get the GtkBuilder-instantiated Button, and connect a signal handler:
    Gtk::MenuItem* pQPMI = nullptr;
    refBuilder->get_widget("QuitProjectMenuItem", pQPMI);
    if(pQPMI)
    {
      pQPMI->signal_activate().connect( sigc::ptr_fun(on_quit) );
    }

    app->run(*pAW);
  }

  delete pAW;

  return 0;
}
