#include "mainwin.h"
#include "entrydialog.h"
#include <sstream>
#include <iomanip>

Mainwin::Mainwin():store{new Store}{

	set_default_size(800,600);
	set_title("ELSA");
	//put a vetrical box contaier 
	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

	//Menu 
	//adding menu bar on top of the window
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);
	
	//File
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem ("_File",true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//new_store
	Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store",true));
	filemenu->append(*menuitem_new);
	
	//save
	Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save",true));
	filemenu->append(*menuitem_save);
	
	//Save as
	Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save as",true));
	filemenu->append(*menuitem_saveas);
	
	//open 
	Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open",true));
	filemenu->append(*menuitem_open);

	//quit
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect([this]{this->on_quit_click();});
	filemenu->append (*menuitem_quit);

	//View
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem ("_View",true));
	menubar->append (*menuitem_view);
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
	viewmenu->append(*menuitem_desktop);

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
	insert->set_submenu(*insertmenu);
	
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
	menuitem_order1->signal_activate().connect(
		[this]{this->on_insert_desktop_click();});
	insertmenu->append(*menuitem_order1);

	//Insert customer
	Gtk::MenuItem *menuitem_customer1 = Gtk::manage(new Gtk::MenuItem("_Customer", true));
	menuitem_customer1->signal_activate().connect(
		[this]{this->on_insert_customer_click();});
	insertmenu->append(*menuitem_customer1);

	
	//Help menu
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar->append(*menuitem_help);
	Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*helpmenu);
	
	//About under help
	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About",true));
	menuitem_about->signal_activate().connect([this]{this->on_about_click();});
	helpmenu->append(*menuitem_about);

	//Data Display
	data = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
	data->set_hexpand();
	
	Gtk::EventBox *eb = Gtk::manage(new Gtk::EventBox);
	eb->add(*data);
	
	vbox->pack_start(*eb, Gtk::PACK_EXPAND_WIDGET,0);
	
	msg = Gtk::manage(new Gtk::Label);
	msg->set_hexpand();
	
	vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
	

	vbox->show_all();
}



Mainwin::~Mainwin(){ }

void Mainwin:: on_quit_click(){
	close();
}

void Mainwin:: on_view_peripheral_click(){
	 std::ostringstream oss;
	 for(int i=0; i< store->num_options(); ++i) 
          oss << i << ") " << store->option(i) << "\n";
     set_data(oss.str());
     set_msg("");
}
void Mainwin:: on_view_desktop_click(){
	 std::ostringstream oss;
	 for(int i=0; i< store->num_desktops(); ++i)                
          oss<< i << ") " << store->desktop(i) << "\n";
     set_data(oss.str());
     set_msg("");
}
void Mainwin:: on_view_order_click(){
	std::ostringstream oss;
 	for(int i=0; i< store->num_orders(); ++i) 
          oss<< i << ") " << store->order(i) << "\n";
     set_data(oss.str());
     set_msg("");
}
void Mainwin:: on_view_customer_click(){
	 std::ostringstream oss;
	 for(int i=0; i< store->num_customers(); ++i) 
           oss<< i << ") " << store->customer(i) << "\n";
     set_data(oss.str());
     set_msg("");
}

//Inserting data.......

void Mainwin::on_insert_peripheral_click(){
	std::string s = get_string("Enter the Name of peripheral");
	double cost = get_double("Enter the cost");
	
    Options option{s, cost};
    store->add_option(option);
    
    on_view_peripheral_click();
    set_msg("Added peripheral "+ s);
}
void Mainwin::on_insert_desktop_click(){
 on_view_peripheral_click();
 int desktop = store->new_desktop();
            while(true) {
            	std::ostringstream oss;
                oss << store->desktop(desktop) << "\n\nAdd which peripheral(-1 when done?)";
                int option = get_int(oss.str());
                //std::cin >> option; std::cin.ignore(32767, '\n');
                if(option == -1) break;
                try {
                    store->add_option(option, desktop);
                } catch(std::exception& e) {
                    Gtk::MessageDialog{*this, "#### INVALID OPTION ####\n\n"}.run(); 
                }
            }
            on_view_desktop_click();
            set_msg("Added desktop" + std::to_string(desktop));

}	

void Mainwin::on_insert_order_click() {
    on_view_customer_click();

    int customer = get_int("Customer?");
    if(customer == -1) return;

    int order = store->new_order(customer);

    on_view_desktop_click();
    while(true) {
        int desktop = get_int("Desktop (-1 when done)?");

        if(desktop == -1) break;
        store->add_desktop(desktop, order);
    }

    on_view_order_click();
    set_msg("Added order " + std::to_string(order) + " for $" + std::to_string(store->order(order).price()));
}

void Mainwin:: on_insert_customer_click(){
	std::string name = get_string("Enter Name of customer");
	if (name.size()){
		std::string phone = get_string("Customer Phone Number(xxx-xxx-xxxx)?");
		std::string email = get_string("Customer email address(xxx@domain.com)?");
		Customer customer (name, phone, email);
		store->add_customer(customer);
	}
	on_view_customer_click();
	set_msg("Added customer " + name);
}
void Mainwin::on_about_click(){
	Gtk::AboutDialog dialog;
	dialog.set_transient_for(*this);
	dialog.set_program_name("ELSA");
	//auto logo = Gdk::Pixbuf::create_from_file("elsa.png");
	//dialog.set_logo(logo);
	dialog.set_version("Version 0.2.0");
	dialog.set_copyright("Copyright 2020");
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	std::vector<Glib::ustring> authors = {"Santosh Bhandari"};
	dialog.set_authors(authors);
	dialog.run();
	set_msg("");
}

///Utilities
void Mainwin::set_data(std::string s){data->set_markup(s);}
void Mainwin::set_msg(std::string s){msg ->set_markup(s);}

std::string Mainwin::get_string(std::string prompt){
	EntryDialog ed_string{*this, prompt};
	ed_string.run();
	return ed_string.get_text();
}
double Mainwin:: get_double(std::string prompt){
	try{
		return std::stod(get_string(prompt));
	}catch(std::exception& e){
		return -1.0;
	}
}
int Mainwin::get_int(std::string prompt){
	try{
		return std::stoi(get_string(prompt));
	}catch(std::exception& e){
		return -1;
	}
}



