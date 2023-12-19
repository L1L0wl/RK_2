#include <iostream>
#include <vector>

// Базовый класс Animal
class Animal {
protected:
    std::string name;
    std::string species;

public:
    // Конструктор
    Animal(const std::string& n, const std::string& s) : name(n), species(s) {}

    // Виртуальный деструктор
    virtual ~Animal() {}

    // Виртуальная функция для вывода информации
    virtual void display() const {
        std::cout << "Animal: " << species << ", Name: " << name;
    }
};

// Класс Bird, наследуемый от Animal
class Bird : public Animal {
private:
    std::string wingspan;

public:
    // Конструктор
    Bird(const std::string& n, const std::string& ws) : Animal(n, "Bird"), wingspan(ws) {}

    // Переопределенная функция display
    void display() const override {
        Animal::display();
        std::cout << ", Wingspan: " << wingspan << std::endl;
    }
};

// Класс Mammal, наследуемый от Animal
class Mammal : public Animal {
private:
    std::string furType;

public:
    // Конструктор
    Mammal(const std::string& n, const std::string& ft) : Animal(n, "Mammal"), furType(ft) {}

    // Переопределенная функция display
    void display() const override {
        Animal::display();
        std::cout << ", Fur Type: " << furType << std::endl;
    }
};

// Функция для изменения характеристик животного
void modifyAnimal(Animal* animal) {
    // Меняем характеристики в зависимости от типа объекта
    if (Bird* bird = dynamic_cast<Bird*>(animal)) {
        bird->display(); // Для примера, выводим текущую информацию
        bird->display(); // Меняем характеристику птицы
    }
    else if (Mammal* mammal = dynamic_cast<Mammal*>(animal)) {
        mammal->display();
        mammal->display();
    }
}

int main() {
    // Создаем контейнер для хранения указателей на объекты Animal
    std::vector<Animal*> animals;

    // Заполняем контейнер объектами Bird и Mammal
    animals.push_back(new Bird("Eagle", "2 meters"));
    animals.push_back(new Mammal("Lion", "Short"));

    // Используем итераторы STL для вывода информации о каждом животном
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        (*it)->display();
    }

    // Вызываем функцию для изменения характеристик животных
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        modifyAnimal(*it);
    }

    // Освобождаем выделенную память
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        delete* it;
    }

    return 0;
}
