#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin():store{nullptr}{
	set_default_size(400,200);
	set_title("ELSA");
	//put a vetrical box contaier 
	Gtk::Box *vbox = Gtk::manage(new Gtk::Vbox);
	add(*vbox);
	
	//Menu 
	//adding menu bar on top of the window
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);
	
	//File
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem ("_File",true));
	Gtk::menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//quit
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect(
		[this]{this->on_quit_click();});
	filemenu->append (*menuitem_quit);
	//View
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem ("_View",true));
	Gtk::menubar->append (*menuitem_view);
	Gtk:: Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);
	
	//view peripheral
	Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral",true));
	menuitem_peripheral->signal_activate().connect(
		[this]{this->on_view_peripheral_click();});
	viewmenu->append(*menuitem_peripheral);

	//view desktop
	Gtk::MenuItem *menuitem_desktop = Gtk::manage (new Gtk::MenuItem("_Desktop",true));
	menuitem_desktop->signal_activate().connect(
		[this]{this->on_view_desktop_click();});
	viewmenu->append(*menuitem_peripheral);

	//view order
	Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
	menuitem_order->signal_activate().connect(
		[this]{this->on_view_order_click();});
	viewmenu->append(*menuitem_order);

	//view customer
	Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer",true));
	menuitem_customer->signal_activate().connect(
		[this]{this->on_view_customer_click();});
	viewmenu->append(*menuitem_customer);

	//insert and insert menu
	Gtk::MenuItem *insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	menubar->append(*insert);
	Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
	insert->set_submenu(insertmenu);
	
	//Insert Peripheral
	Gtk::MenuItem *menuitem_peripheral1 = Gtk::manage(new Gtk::MenuItem("_Peripheral",true));
	menuitem_peripheral1->signal_activate().connect(
		[this]{this->on_insert_peripheral_click();});
	insertmenu->append(*menuitem_peripheral1);
	
	//Insert desktop
	Gtk::MenuItem *menuitem_desktop1 = Gtk::manage(new Gtk::MenuItem("_Desktop",true));
	menuitem_desktop1 ->signal_activate().connect(
		[this]{this->on_insert_desktop_click();});
	insertmenu->append(*menuitem_desktop1);

	//Insert order
	Gtk::MenuItem *menuitem_order1 = Gtk::manage(new Gtk::MenuItem("_Order", true));
	menuitem_oder1->signal_activate().connect(
		[this]{this->on_insert_desktop_click();});
	insertmenu->append(*menuitem_order1);

	//Insert customer
	Gtk::MenuItem *menuitem_customer1 = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
	menuitem_customer1->signal_activate().connect(
		[this]{this->on_insert_customer_click();});
	insertmenu->append(*menuitem_customer1);

	
	//Help menu
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menuitem_help->signal_activate().connect(
		[this]{this->on_about_click();});
	menubar->append(*menuitem_help);
	
	

Mainwin::~Mainwin();
void Mainwin:: on_quit_click(){
	
}

void Mainwin:: on_view_peripheral_click(){
	 for(int i=0; i<store.num_options(); ++i) 
               std::cout << i << ") " << store.option(i) << "\n";
}
void Mainwin:: on_view_desktop_click(){
	 for(int i=0; i<store.num_desktops(); ++i) 
                    std::cout << i << ") " << store.desktop(i) << "\n";
}
void Mainwin:: on_view_order_click(){
 	for(int i=0; i<store.num_orders(); ++i) 
                std::cout << i << ") " << store.order(i) << "\n";
}
void Mainwin:: on_view_customer(){
	 for(int i=0; i<store.num_customers(); ++i) 
                std::cout << i << ") " << store.customer(i) << "\n";
}
void Mainwin:: on_insert_peripheral_click(){
	 std::cout << "Name of new peripheral? ";
            std::string s;
            std::getline(std::cin, s);
            std::cout << "Cost? ";
            double cost;
            if (std::cin >> cost) {
                Options option{s, cost};
                store.add_option(option);
            } else {
                std::cin.clear();
                std::cerr << "#### INVALID PRICE ####\n\n";
                std::cin.ignore(32767, '\n');
            }
}

void Mainwin::on_button_click() {
    EntryDialog edialog{*this, "<big>EntryDialog Demo</big>", true};
    edialog.set_secondary_text("What <i>shall</i> we display <b>today</b>?", true);
    edialog.set_text("Nothing to report...");
    edialog.run();

    Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    mdialog.run();
}
	
	

}
