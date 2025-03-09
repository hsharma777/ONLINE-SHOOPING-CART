#include <iostream> 
#include <string> 
 
const int MAX_PRODUCTS = 100; 
const int MAX_CART_ITEMS = 10; 
 
class Product { 
public: 
    int id; 
    std::string name; 
    double price; 
    int stock; 
 
    Product(int pid = 0, const std::string& pname = "", double pprice = 0.0, int pstock = 0) 
        : id(pid), name(pname), price(pprice), stock(pstock) {} 
 
    void display() const { 
        std::cout << id << ": " << name << " - $" << price << " (" << stock << " in stock)\n"; 
    } 
}; 
 
class User { 
public: 
    std::string username; 
 
    User(const std::string& uname = "Guest") : username(uname) {} 
 
    void displayUserType() const { 
        if (username == "Guest") { 
            std::cout << "User Type: Guest User\n"; 
        } else { 
            std::cout << "User Type: Registered User (" << username << ")\n"; 
        } 
    } 
}; 
 
class Cart { 
private: 
    Product items[MAX_CART_ITEMS]; 
    int quantities[MAX_CART_ITEMS]; 
    int count; 
 
public: 
    Cart() : count(0) {} 
 
    void addItem(const Product& product, int quantity) { 
        if (count >= MAX_CART_ITEMS) { 
            std::cout << "Cart is full.\n"; 
            return; 
        } 
        if (product.stock < quantity) { 
            std::cout << "Not enough stock for " << product.name << ".\n"; 
            return; 
        } 
        for (int i = 0; i < count; ++i) { 
            if (items[i].id == product.id) { 
                quantities[i] += quantity; 
                std::cout << product.name << " quantity updated in cart.\n"; 
                return; 
            } 
        } 
        items[count] = product; 
        quantities[count] = quantity; 
        count++; 
        std::cout << product.name << " added to cart.\n"; 
    } 
 
    void displayCart() const { 
        if (count == 0) { 
            std::cout << "Cart is empty.\n"; 
            return; 
        } 
        std::cout << "Cart items:\n"; 
        double total = 0; 
        for (int i = 0; i < count; ++i) { 
            std::cout << items[i].name << " x" << quantities[i] 
                      << " - $" << (items[i].price * quantities[i]) << "\n"; 
            total += items[i].price * quantities[i]; 
        } 
        std::cout << "Total: $" << total << "\n"; 
    } 
 
    double getTotal() const { 
        double total = 0; 
        for (int i = 0; i < count; ++i) { 
            total += items[i].price * quantities[i]; 
        } 
        return total; 
    } 
}; 
 
class Payment { 
public: 
    static void process(double amount) { 
        std::cout << "Processing payment of $" << amount << "...\n"; 
        std::cout << "Payment successful!\n"; 
    } 
}; 
 
int main() { 
    Product products[MAX_PRODUCTS] = { 
        Product(1, "Laptop", 999.99, 5), 
        Product(2, "Smartphone", 499.99, 10), 
        Product(3, "Tablet", 299.99, 8) 
    }; 
 
    User user("JohnDoe");  
    user.displayUserType(); 
 
    Cart cart; 
    cart.addItem(products[0], 1);  
    cart.addItem(products[1], 2);  
    cart.displayCart(); 
 
    double total = cart.getTotal(); 
    Payment::process(total); 
 
    return 0; 
}