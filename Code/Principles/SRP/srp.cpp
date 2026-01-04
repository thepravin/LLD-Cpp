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

// 1. Shopping cart handeling single responsibilite
class ShoppingCart
{
private:
    vector<Product *> prodcuts; // has-a relationship

public:
    void addProduct(Product *p)
    {
        prodcuts.push_back(p);
    }

    const vector<Product *> getProducts()
    {
        return prodcuts;
    }

    // 1. Calculate total price in cart.
    double calculateTotal()
    {
        double total = 0;
        for (auto p : prodcuts)
        {
            total += p->price;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoice
class ShoppingCartPriner
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPriner(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProducts())
        {
            cout << p->name << " - $" << p->price << endl;
        }

        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartStorage(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void saveToDatabase()
    {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 150000));
    cart->addProduct(new Product("Mouse", 50));

    ShoppingCartPriner* invoice = new ShoppingCartPriner(cart);
    invoice->printInvoice();

    ShoppingCartStorage* store = new ShoppingCartStorage(cart);
    store->saveToDatabase();
}