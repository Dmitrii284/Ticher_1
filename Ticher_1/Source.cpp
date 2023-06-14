#include<vector>
#include <iostream>

class Product
{
protected:
   // int x;
private:
    std::string _name;
    int _amount;
    float _price;
public:
    Product(std::string name, int amount, float price) :
        _amount(amount), _price(price), _name(name) {}

    virtual void Print()
    {
        std::cout << "Name: " << _name << '\n';
        std::cout << "Amount: " << _amount << '\n';
        std::cout << "Price: " << _price << '\n';
    }
    std::string GetName()
    {
        return _name;
    }
};


class Shop
{
private:
    std::vector<Product*> _products;
public:
    void AddProduct(Product* product)
    {
        _products.push_back(product);
    }
    void PrintProducts()
    {
        for (const auto& it : _products)
        {
            it->Print();
        }
    }
    void DeleteProduct(std::string name)
    {
        for (auto it = _products.begin(); it != _products.end(); ++it)
        {
            if (name == (*it)->GetName())
            {
                _products.erase(it);
                delete(*it);
                return;
            }
        }
    }
};


class Banan : public Product
{
private:
    int _percentSweetness;
public:
    Banan(int amount, float price, int percentSweetness) :
        Product("Banan", amount, price), _percentSweetness(percentSweetness) {}

    void Print()
    {
        Product::Print();
        std::cout << "Percent of switness: " << _percentSweetness << '%' << '\n';
    }
};

int main()
{
    Banan banan(20, 45.54, 80);
    banan.Print();
    AddProduct();
    return{};
}