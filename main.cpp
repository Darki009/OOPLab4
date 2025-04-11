#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// ========================
// Класс управления запасами
// Ответственность - управление запасами: добавление, удаление, проверка
// ========================
class Warehouse {
private:
    std::vector<std::string> inventory;

public:
    void addItem(const std::string& item) {
        inventory.push_back(item);
        std::cout << "Добавлен товар на склад: " << item << std::endl;
    }

    void removeItem(const std::string& item) {
        auto it = std::find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
            std::cout << "Удален товар со склада: " << item << std::endl;
        } else {
            std::cout << "Товар не найден: " << item << std::endl;
        }
    }

    bool hasItem(const std::string& item) {
        return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
    }
};

// ========================
// Класс обработки заказов
// Ответственность - обработка заказов: проверка наличия и удаление товара
// ========================
class OrderProcessor {
private:
    Warehouse& warehouse;

public:
    OrderProcessor(Warehouse& wh) : warehouse(wh) {}

    void processOrder(const std::string& item) {
        std::cout << "Обработка заказа на товар: " << item << std::endl;
        if (warehouse.hasItem(item)) {
            warehouse.removeItem(item);
            std::cout << "Заказ обработан успешно." << std::endl;
        } else {
            std::cout << "Не удалось обработать заказ: товар отсутствует." << std::endl;
        }
    }
};

// ========================
// Класс управления доставкой
// Ответственность - организация доставки товара по адресу
// ========================
class DeliveryManager {
public:
    void deliverItem(const std::string& item, const std::string& address) {
        std::cout << "Отправка товара \"" << item << "\" по адресу: " << address << std::endl;
    }
};

int main() {
    system("chcp 65001>nul");
    Warehouse warehouse;
    warehouse.addItem("Ноутбук");
    warehouse.addItem("Монитор");
    warehouse.addItem("Клавиатура");

    OrderProcessor orderProcessor(warehouse);
    orderProcessor.processOrder("Ноутбук");

    DeliveryManager deliveryManager;
    deliveryManager.deliverItem("Ноутбук", "ул. Примерная, д. 42");

    return 0;
}