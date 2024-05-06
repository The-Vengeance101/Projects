#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int last;

void tlast(){
    
    ifstream file("last_track.txt");
    file>>last;

}

class product { 
    
private:

    int no;
    string name;
    string description;
    string brand;
    int quantity;
    double price;
    string supplier;

public:

    friend void store_data(product p[]);

    void disp(int i){

        cout << "Product " << i + 1 << ": " ;
        cout<< name <<endl<<description<<endl<<"Brand : "<<brand<<endl<<"Quantity : "<<quantity<<endl<<"Price : "<<price<<endl<<"Supplier :"<<supplier<<endl<<endl;  
    }
    
    string get_name(){

        return name;
    }

    void search_result(int i){

         cout << "Product " << i + 1 << ": " << name <<" Quantity"<<quantity<<" Price"<<price<<endl<<endl;  

    }

   
};





void store_data(product p[]) {

    ifstream file("data.txt");

    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    for (int i = 0; i < last; ++i) {
        file >> p[i].no;
        file >> p[i].name;
        file >> p[i].description;
        file >> p[i].brand;
        file >> p[i].quantity;
        file >> p[i].price;
        file >> p[i].supplier;
    }

    file.close();
}

void add_product(product p[]){

    int tno;
    string tname;
    string tdescription;
    string tbrand;
    int tquantity;
    double tprice;
    string tsupplier;

    tno = last + 1;
    cout<<"Enter product name :";
    cin>>tname;
    cout<<"Enter product Description :";
    cin>>tdescription;
    cout<<"Enter product brand :";
    cin>>tbrand;
    lable2:
        cout<<"Enter product quantity :";
        cin>>tquantity;
        if(tquantity > 40){
            cout<<"Product quantity can not be more than 40."<<endl;
            goto lable2;
        }

    cout<<"Enter product price :";
    cin>>tprice;
    cout<<"Enter product supplier :";
    cin>>tsupplier;

    ofstream file("data.txt", ios::app);
    
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    file << tno << " " << tname << " " << tdescription << " " << tbrand << " " << tquantity << " " << tprice << " " << tsupplier << endl;
    file.close();
    ofstream nfile("last_track.txt");

    if (nfile.is_open()) {
        nfile << last + 1;
        nfile.close();
    }

    // store_data(p);

}
void product_details(product p[]){

    string tproduct,tproduct2;
    cout<<"Enter product name in uppercase letters : ";
    cin>>tproduct;
    bool result = false;

    for (int i = 0; i < last; ++i) {

        
        tproduct2 = p[i].get_name();

        if (tproduct2 == tproduct){
            cout<<"product found !"<<endl<<"Product details : "<<endl;
            p[i].disp(i);
            cout<<endl;
            result = true;
            break;
        }
    }
    if (result == false){

        cout<<"Product not found"<<endl;

    }




}
void products_list(product p[]){

    cout<<endl;
    for (int i = 0; i < last; ++i) {
        p[i].disp(i);
    }
}
void Search_product(product p[]){

    string tproduct,tproduct2;
    cout<<"Enter product name in uppercase letters : ";
    cin>>tproduct;
    bool result = false;

    for (int i = 0; i < last; ++i) {

        
        tproduct2 = p[i].get_name();

        if (tproduct2 == tproduct){
            cout<<"product found !"<<endl<<"Product details : "<<endl;
            p[i].search_result(i);
            cout<<endl;
            result = true;
            break;
        }
    }
    if (result == false){

        cout<<"Product not found"<<endl;
   
    }

}
void Purchase_orders(){

    cout<<endl<<"All orders : "<<endl<<endl;
    ifstream file("orders.txt");
    if (!file.is_open()) {

        cout<< "Error opening the file." << endl;
    }

    string product_name;
    int quantity;
    string place;
    string date;

    while (file >> product_name >> quantity >> place >> date) {
        cout << "Product name : " << product_name << endl;
        cout << "Quantity : " << quantity << endl;
        cout << "Place : " << place << endl;
        cout << "Date : " << date << endl;
        cout << endl;
    }

    

}
void add_order() {

    ofstream file("orders.txt", ios_base::app);
    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
    }

    string product_name;
    int quantity;
    string place;
    string date;

    cout << "Enter product name: ";
    cin >> product_name;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter place: ";
    cin >> place;

    cout << "Enter date: ";
    cin >> date;

    file << endl<<product_name << " " << quantity << " " << place << " " << date << endl;

    file.close();
    cout <<endl <<"Order added successfully." << endl;

}
void shipments(){
    int ans;

    do {
        cout<<endl<<"1. Add shipment"<<endl;
        cout<<"2. View all shipments"<<endl;
        cout<<"Enter your choice: ";
        cin>>ans;

    } while (ans!= 1 && ans!= 2);

    if(ans==1){

        ofstream file("shipments.txt", ios_base::app);

        if (!file.is_open()) {

            cout << "Error opening the file." << endl;

        }

        string product_name;
        int quantity;
        string supplier;
        string date;

        cout << "Enter product name: ";
        cin >> product_name;

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter supplier: ";
        cin >> supplier;

        cout << "Enter date: ";
        cin >> date;

        file << endl<<product_name << " " << quantity << " " << supplier << " " << date << endl;

        file.close();
        cout <<endl <<"Shipment added successfully." << endl;
    }

    else if(ans == 2){

        cout<<endl<<"All shipments : "<<endl<<endl;
        ifstream file("shipments.txt");

        if (!file.is_open()) {

            cout<< "Error opening the file." << endl;
        }

        string product_name;
        int quantity;
        string supplier;
        string date;

        while (file >> product_name >> quantity >> supplier >> date) {

            cout << "Product name : " << product_name << endl;
            cout << "Quantity : " << quantity << endl;
            cout << "supplier : " << supplier << endl;
            cout << "Date : " << date << endl;
            cout << endl;
        }
    }

}
void sales_report(){

    cout<<endl<<"All sales : "<<endl<<endl;
    ifstream file("sales.txt");

    if (!file.is_open()) {

        cout<< "Error opening the file." << endl;
    }

    string product_name;
    int quantity;
    string date;
    int index = 1;

    while (file >> product_name >> quantity >> date) {

        cout<<"sale "<<index<<" : "<<endl;
        index++;
        cout << "Product name : " << product_name << endl;
        cout << "Quantity : " << quantity << endl;
        cout << "Sold on Date : " << date << endl;
        cout << endl;

    }

}




int main ()
{
    tlast();
    product p[50]; 

    store_data(p);

   system("cls");

    int ans;
   
    do {


        cout<<endl<<endl<< "\033[3;7;4m" << " Inventory management system program " << "\033[0m";
        cout<<endl<<endl;
        cout<<"List of oparations."<<endl<<endl;
        cout<<"1. Add product"<<endl;
        cout<<"2. View product details"<<endl;
        cout<<"3. list of all products"<<endl;
        cout<<"4. Search product."<<endl;
        cout<<"5. Purchase orders"<<endl;
        cout<<"6. Add Purchase order"<<endl;
        cout<<"7. Shipment "<<endl;
        cout<<"8. Sales report"<<endl;
        cout<<"9. Exit"<<endl;

        cout<<endl<<"Enter number of operation : ";
        cin>>ans;

        switch(ans) {

            case 1 :
                add_product(p);
                break;

            case 2 :
                product_details(p);
                break; 

            case 3 :
                products_list(p);
                break;

            case 4 :
                Search_product(p);
                break;

            case 5 :
                Purchase_orders();
                break;

            case 6 :
                add_order();
                break;

            case 7 :
               shipments(); 
                break;

            case 8 :
                sales_report();
                break;

            case 9 :
                cout<<"Exiting the program..."<<endl;
                exit(0);
                break;

            default :
                cout<<"Invalid input. try again"<<endl;
                break;

        }


    } while (ans!= 9);
    
    
    return 0;
}