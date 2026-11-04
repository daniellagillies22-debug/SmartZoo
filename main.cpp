#include <iostream> #include <string> #include <vector> using namespace std;
// Preprocessor macros #define ZOO_NAME "Smart Zoo" #define INITIAL_HEALTH 100 #define DEBUG_MODE
#ifdef DEBUG_MODE #define DEBUG_LOG(message) cout << "[DEBUG] " << message << endl #else #define DEBUG_LOG(message) #endif
// Base class class Animal { protected: string name; int age; int health;
public: Animal(string name, int age) { this->name = name; this->age = age; health = INITIAL_HEALTH; DEBUG_LOG("Animal created: " << name); }
virtual void showInfo() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Health: " << health << endl;
}

void feed() {
    health += 10;
    if (health > 100) health = 100;
    DEBUG_LOG(name << " health set to " << health);
}

void heal() {
    health += 20;
    if (health > 100) health = 100;
    DEBUG_LOG(name << " health set to " << health);
}

void takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    DEBUG_LOG(name << " received damage: " << damage);
    DEBUG_LOG(name << " health set to " << health);

    if (health < 30) {
        cout << "Warning: " << name
             << " needs medical help!" << endl;
    }
}

virtual void makeSound() {
    cout << "Unknown sound" << endl;
}

string getName() const {
    return name;
}

virtual ~Animal() {}
};
// Lion class class Lion : public Animal { private: int power;
public: Lion(string name, int age, int power) : Animal(name, age) { this->power = power; }
void showInfo() override {
    cout << "Animal: Lion" << endl;
    Animal::showInfo();
    cout << "Power: " << power << endl;
}

void makeSound() override {
    cout << "Roar!" << endl;
}
};
// Elephant class class Elephant : public Animal { private: int weight;
public: Elephant(string name, int age, int weight) : Animal(name, age) { this->weight = weight; }
void showInfo() override {
    cout << "Animal: Elephant" << endl;
    Animal::showInfo();
    cout << "Weight: " << weight << " kg" << endl;
}

void makeSound() override {
    cout << "Trumpet!" << endl;
}
};
// Parrot class class Parrot : public Animal { private: int wordsKnown;
public: Parrot(string name, int age, int wordsKnown) : Animal(name, age) { this->wordsKnown = wordsKnown; }
void showInfo() override {
    cout << "Animal: Parrot" << endl;
    Animal::showInfo();
    cout << "Words known: " << wordsKnown << endl;
}

void makeSound() override {
    cout << "Squawk! Hello!" << endl;
    wordsKnown++;
}
};
// ZooKeeper class class ZooKeeper { private: string name; int experience;
public: ZooKeeper(string name, int experience) { this->name = name; this->experience = experience; }
void feedAnimal(Animal* animal) {
    DEBUG_LOG(name << " feeds " << animal->getName());
    animal->feed();
}

void healAnimal(Animal* animal) {
    DEBUG_LOG(name << " heals " << animal->getName());
    animal->heal();
}

void showInfo() {
    cout << "ZooKeeper: " << name << endl;
    cout << "Experience: " << experience
         << " years" << endl;
}
};
// Main function int main() { cout << "Welcome to " << ZOO_NAME << endl << endl;
ZooKeeper keeper("John", 5);

Lion* lion = new Lion("Leo", 5, 80);
Elephant* elephant = new Elephant("Dumbo", 12, 5000);
Parrot* parrot = new Parrot("Kesha", 2, 15);

vector<Animal*> animals;
animals.push_back(lion);
animals.push_back(elephant);
animals.push_back(parrot);

keeper.showInfo();

cout << "\n----------------------" << endl;

for (Animal* animal : animals) {
    animal->showInfo();
    cout << endl;
    animal->makeSound();
    cout << "\n----------------------" << endl;
}

keeper.feedAnimal(lion);
cout << endl;

keeper.healAnimal(elephant);
cout << endl;

lion->takeDamage(80);

cout << "\n----------------------" << endl;
cout << "Updated information:" << endl << endl;

for (Animal* animal : animals) {
    animal->showInfo();

    if (animal != animals.back()) {
        cout << "\n----------------------" << endl;
    }
}

for (Animal* animal : animals) {
    delete animal;
}

cout << "\nProgram finished successfully." << endl;

return 0;
}
