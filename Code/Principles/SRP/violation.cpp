#include <iostream>
#include <vector>
using namespace std;

// Product class representing any item of any ECommerce
class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }

    ~Product() {}
};

// Violating SRP: shopping cart handeling multiple responsibilites
class ShoppingCart
{
private:
    vector<Product *> prodcuts;  // has-a relationship

public:
    void addProduct(Product *p)
    {
        prodcuts.push_back(p);
    }

    const vector<Product*> getProducts(){
        return prodcuts;
    }

    // 1. Calculate total price in cart.
    double calculateTotal(){
        double total = 0;
        for(auto p : prodcuts){
            total += p->price;
        }
        return total;
    }


    // 2. Violating SRP - Prints invoice (Should be in seperate class)
    void printInvoice(){
        cout<<"Shopping Cart Invoice:\n";
        for (auto p :prodcuts){
            cout<<p->name<<" - $"<<p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    }

    // 3. Violating SRP - Saves to DB (Should be in seperate class)
    void saveToDatabase(){
        cout<<"Saving shopping cart to database..."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop",150000));
    cart->addProduct(new Product("Mouse",50));

    cart->printInvoice();
    cart->saveToDatabase();
}