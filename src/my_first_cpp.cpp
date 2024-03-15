#include <iostream>
#include <vector>

struct Person {
    std::string name;
    int age;
    //constructor
    Person(std::string n, int a) : name(n), age(a) {
        std::cout << "constructor called\n";
    }
    
    void print_info() {
        std::cout << name << " " << age << "\n";
    }
    
    //destructor
    ~Person() {
        std::cout << "destructor called\n";
    }
};


int main()
{
    std::cout << "Hello World!\n";
    std::vector<std::string> v = {"paul","yan","hi","idk","heloo"};    

    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << "\n";
    }
    //create a person
    Person p("paul", 20);
    p.print_info();

    std::vector<Person> people;
    people.push_back(Person("paul", 20));
    people.push_back(Person("yan", 20));
    people.push_back(Person("hi", 20));
    people.push_back(Person("idk", 20));
    people.push_back(Person("heloo", 20));

    for (Person it : people) {
        it.print_info();
    }

    for (auto it = people.begin(); it != people.end(); it++) {
        (*it).print_info();
    }


    return 0;
}
